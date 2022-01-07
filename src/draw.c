#include "fdf.h"
#include <math.h>

#define MAX(a,b) (a > b ? a : b)

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
	//printf("%s%s", "dst is ", dst);
}

void isometric (float *x, float *y, int z)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    //printf("\niso\n");
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = (previous_x + previous_y) * sin(0.523599) - z;
}

void bresenham(float x, float y, float x1, float y1, fdf *data)
{
    float x_step;
    float y_step;
    int max;
    int z;
    int z1;

    //printf("\ny: %f\n", y);

    z = data->z_matrix[(int)y][(int)x];
    z1 = data->z_matrix[(int)y1][(int)x1];

    //--------------zoom------
    x *= data->zoom;
    y *= data->zoom;
    x1 *= data->zoom;
    y1 *= data->zoom;
    //---------------color-----
    data->color = (z || z1) ? 0xe80c0c : 0xffffff;
    //---------3D--------------
    isometric(&x, &y, z);
    isometric(&x1, &y1, z1);
    //--------------shift--------
    x += data->shift_x;
    x1 += data->shift_x;
    y += data->shift_y;
    y1 += data->shift_y;

    x_step = x1 - x;
    y_step = y1 - y;
    max = MAX(fabs(x_step), fabs(y_step));
    x_step /= max;
    y_step /= max;
    //printf("\nbresenham start x,y: %f %f\n", x, y);
    while(((int)(x - x1) || (int) (y - y1)) && x >= 0 && y >= 0 && x < WINDOW_WIDTH && y < WINDOW_HEIGHT)
    {
        //mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + WINDOW_WIDTH/2, y + WINDOW_HEIGHT/2, data->color);
        my_mlx_pixel_put (&data->img, x, y, data->color); //+ WINDOW_WIDTH/2  + WINDOW_HEIGHT/2
        x += x_step;
        y += y_step;
    }
    //printf("\nbresenham end\n");
    
}

void clearColorBuffer(int color, t_data* img)
{
	for (int x = 0; x < WINDOW_WIDTH; x++)
	{
		for (int y = 0; y < WINDOW_HEIGHT; y++)
		{
			//colorBuffer[WINDOW_WIDTH * y + x] = color;
			my_mlx_pixel_put (img, x, y, color);
			//mlx_pixel_put(vars.mlx, vars.win, x, y, color);
			//color = 0;
		}
	}
}

void draw(fdf *data)
{
    int x;
    int y;

    
    y = 0;
    //x = 0;
    clearColorBuffer(0x0, &data->img);
    //printf("\ndraw start\n");
    while(y < data->height)
    {
        //printf("\ndraw y\n");
        x = 0;
        while (x < data ->width)
        {
            
            if(x < data->width - 1)
                bresenham(x, y, x + 1, y, data);
            if(y < data->height - 1)
                bresenham(x, y, x, y + 1, data);
            x++;
            //printf("\ndraw x: %d\n", x);
        }
        y++;
    }
    //printf("\ndraw end\n");
    
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
}