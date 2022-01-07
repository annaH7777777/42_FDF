#include "fdf.h"

int	close_programm(fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data);
	exit(0);
}

int	deal_key_press(int key, fdf *data)
{
    //printf("\nkey: %d\n", key);
	if (key == 126)
		data->shift_y += 10;
	else if (key == 125)
		data->shift_y -= 10;
	else if (key == 123)
		data->shift_x += 10;
	else if (key == 124)
		data->shift_x -= 10;
	else if (key == 53)
		close_programm(data);
	else
		return 0;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
    
    return (0);
}

// int deal_key_release(int key, fdf *data)
// {
    //printf("\nkey: %d\n", key);
    // if(key == 126)
    //     data->shift_y = 0;
    // else if(key == 125)
    //     data->shift_y = 0;
    // else if(key == 123)
    //     data->shift_x = 0;
    // else if(key == 124)
    //     data->shift_x = 0;
    // else
    //     return 0;
//     mlx_clear_window(data->mlx_ptr, data->win_ptr);
//     draw(data);
    
//     return (0);
// }

int	main(int argc, char **argv)
{
	fdf *data;

	if(argc != 2)
		return (-1);
	data = (fdf*) malloc(sizeof(fdf));
	read_file(argv[1], data);
  

    //int i;
    //int j;

    //i = 0;
    // while(i < data->height)
    // {
    //     j = 0;
    //     while(j < data->width)
    //     {
    //         printf("%3d ", data->z_matrix[i][j]);
    //         j++;
    //     }
    //     printf("\n");
    //     i++;
    // }
	printf("\npid %d\n", getpid());

	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	data->img.img =	mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	data->zoom = 20;
	data->shift_x = WINDOW_WIDTH / 2;
	data->shift_y = WINDOW_HEIGHT / 2;

	draw(data);
	mlx_key_hook(data->win_ptr, deal_key_press, data);
    //mlx_hook(data->win_ptr, 2, 1L << 2, deal_key_press, NULL);
	//mlx_hook(data->win_ptr, 3, 1L << 3, deal_key_release, NULL);
	mlx_loop(data->mlx_ptr);
}