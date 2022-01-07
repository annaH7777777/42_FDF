#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

float	max_number(float a, float b)
{
	float	c;

	if (a > b)
		c = a;
	else
		c = b;
	return (c);
}

void	isometric(float *x, float *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (previous_x + previous_y) * sin(0.523599) - z;
}

void	bresenham(float x, float y, float x1, float y1, fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	if (z || z1)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	x += data->shift_x;
	x1 += data->shift_x;
	y += data->shift_y;
	y1 += data->shift_y;
	x_step = x1 - x;
	y_step = y1 - y;
	max = max_number(fabs(x_step), fabs(y_step));
	x_step /= max;
	y_step /= max;
	while (((int)(x - x1) || (int)(y - y1)) && x >= 0
	&& y >= 0 && x < WINDOW_WIDTH && y < WINDOW_HEIGHT)
	{
		my_mlx_pixel_put (&data->img, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	clear_color_buffer(int color, t_data *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < WINDOW_WIDTH)
	{
		while (y < WINDOW_HEIGHT)
		{
			my_mlx_pixel_put (img, x, y, color);
			y++;
		}
		x++;
	}
}

void	draw(fdf *data)
{
	int	x;
	int	y;

	y = 0;
	clear_color_buffer(0x0, &data->img);
	while (y < data->height)
	{
		x = 0;
		while (x < data ->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
}
