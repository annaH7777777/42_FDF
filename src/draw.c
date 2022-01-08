/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <annharut@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:20:52 by annharut          #+#    #+#             */
/*   Updated: 2022/01/08 20:33:21 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_z(t_coords *coords, t_fdf *data)
{
	coords->z = data->z_matrix[(int)coords->y][(int)coords->x];
	coords->z1 = data->z_matrix[(int)coords->y1][(int)coords->x1];
}

void	bresenham(t_coords *coords, t_fdf *data)
{
	float	x_step;
	float	y_step;
	float	max;

	fill_z(coords, data);
	zoom(coords, data);
	if (coords->z || coords->z1)
		data->color = rgb(255, 0, 0);
	else
		data->color = rgb(255, 255, 255);
	isometric(coords);
	shift(coords, data);
	x_step = coords->x1 - coords->x;
	y_step = coords->y1 - coords->y;
	max = max_number(fabs(x_step), fabs(y_step));
	x_step /= max;
	y_step /= max;
	while (((int)(coords->x - coords->x1)
		|| (int)(coords->y - coords->y1)) && coords->x >= 0
	&& coords->y >= 0 && coords->x < WINDOW_WIDTH && coords->y < WINDOW_HEIGHT)
	{
		my_mlx_pixel_put (&data->img, coords->x, coords->y, data->color);
		coords->x += x_step;
		coords->y += y_step;
	}
}

int	draw_x(int x, int y, t_coords *coords, t_fdf *data)
{
	coords->x = x;
	coords->y = y;
	coords->x1 = x + 1;
	coords->y1 = y;
	bresenham(coords, data);
	return (0);
}

int	draw_y(int x, int y, t_coords *coords, t_fdf *data)
{
	coords->x = x;
	coords->y = y;
	coords->x1 = x;
	coords->y1 = y + 1;
	bresenham(coords, data);
	return (0);
}

int	draw(t_fdf *data)
{
	int			x;
	int			y;
	t_coords	coords;

	y = -1;
	clear_color_buffer(data);
	while (++y < data->height)
	{
		x = -1;
		while (++x < data ->width)
		{
			if (x < data->width - 1)
				draw_x(x, y, &coords, data);
			if (y < data->height - 1)
				draw_y(x, y, &coords, data);
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	return (0);
}
