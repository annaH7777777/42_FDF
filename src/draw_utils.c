/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <annharut@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:44:07 by annharut          #+#    #+#             */
/*   Updated: 2022/01/08 21:58:42 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	clear_color_buffer(t_fdf *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
			my_mlx_pixel_put(&data->img, x, y, rgb(0, 0, 0));
	}
}

void	isometric(t_coords *coords)
{
	int	previous_x;
	int	previous_y;
	int	previous_x1;
	int	previous_y1;

	previous_x = coords->x;
	previous_y = coords->y;
	coords->x = (previous_x - previous_y) * cos(0.523599);
	coords->y = (previous_x + previous_y) * sin(0.523599) - coords->z;
	previous_x1 = coords->x1;
	previous_y1 = coords->y1;
	coords->x1 = (previous_x1 - previous_y1) * cos(0.523599);
	coords->y1 = (previous_x1 + previous_y1) * sin(0.523599) - coords->z1;
}

void	zoom(t_coords *coords, t_fdf *data)
{
	coords->x *= data->zoom;
	coords->y *= data->zoom;
	coords->x1 *= data->zoom;
	coords->y1 *= data->zoom;
    rotate_x(coords, data);
    rotate_y(coords, data);
    rotate_z(coords, data);
}

void	shift(t_coords *coords, t_fdf *data)
{
	coords->x += data->shift_x;
	coords->x1 += data->shift_x;
	coords->y += data->shift_y;
	coords->y1 += data->shift_y;
}
