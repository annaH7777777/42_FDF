/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <annharut@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:20:12 by annharut          #+#    #+#             */
/*   Updated: 2022/01/08 22:58:08 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int deal_other_keys(int key, t_fdf *data)
{
	if(key == 12)
		data->camera->alpha += 0.05;
	else if(key == 13)
		data->camera->alpha -= 0.05;
	else if(key == 14)
		data->camera->beta += 0.05;
	else if(key == 15)
		data->camera->beta -= 0.05;
	else if(key == 17)
		data->camera->gamma += 0.05;
	else if(key == 16)
		data->camera->gamma -= 0.05;
	else if(key == 35) //p
		data->camera->projection = PARALLEL;
	else if(key == 34) //i
		data->camera->projection = ISO;
	return (0);
}

int	deal_key_press(int key, t_fdf *data)
{
	printf("key %d", key);
	if (key == 126)
		data->shift_y -= 10;
	else if (key == 125)
		data->shift_y += 10;
	else if (key == 123)
		data->shift_x -= 10;
	else if (key == 124)
		data->shift_x += 10;
	else if (key == 53)
		close_programm(data);
	else if(key == 27 && data->zoom >= 1)
		data->zoom -= 1;
	else if(key == 24)
		data->zoom += 1;
	else
		deal_other_keys(key, data);
	return (0);
}

void free_fdf(t_fdf	*data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	int i = -1;
	while (data->z_matrix[++i])
		free(data->z_matrix[i]);
	free(data->z_matrix);
	free(data);
}

void init_camera(t_fdf	*data)
{
	data->zoom = 20;
	data->camera = malloc (sizeof(t_camera));
	data->camera->alpha = 0;
	data->camera->beta = 0;
	data->camera->gamma = 0;
	data->camera->projection = ISO;
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
		terminate ("Incorrect arguments!");
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		terminate("malloc error");
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, "FDF");
	data->img.img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	init_camera(data);
	data->shift_x = WINDOW_WIDTH / 2;
	data->shift_y = WINDOW_HEIGHT / 2;
	mlx_key_hook(data->win_ptr, deal_key_press, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, close_programm, data);
	mlx_loop_hook(data->mlx_ptr, draw, data);
	mlx_loop(data->mlx_ptr);
	free_fdf(data);
}
 