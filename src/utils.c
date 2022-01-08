/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <annharut@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:21:08 by annharut          #+#    #+#             */
/*   Updated: 2022/01/08 22:24:24 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	terminate(char *s)
{
	perror(s);
	exit(1);
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

int	rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	rotate_x(t_coords *coords, t_fdf *data)
{
	int previous_y;
	int previous_y1;

	previous_y = coords->y;
	coords->y = previous_y * cos(data->camera->alpha) + coords->z * sin(data->camera->alpha);
	coords->z = -previous_y * sin(data->camera->alpha) + coords->z * cos(data->camera->alpha);
	previous_y1 = coords->y1;
	coords->y1 = previous_y1 * cos(data->camera->alpha) + coords->z1 * sin(data->camera->alpha);
	coords->z1 = -previous_y1 * sin(data->camera->alpha) + coords->z1 * cos(data->camera->alpha);
}

void	rotate_y(t_coords *coords, t_fdf *data)
{
	int previous_x;
	int previous_x1;

	previous_x = coords->x;
	coords->x = previous_x * cos(data->camera->beta) + coords->z * sin(data->camera->beta);
	coords->z = -previous_x * sin(data->camera->beta) + coords->z * cos(data->camera->beta);
	previous_x1 = coords->x1;
	coords->x1 = previous_x1 * cos(data->camera->beta) + coords->z1 * sin(data->camera->beta);
	coords->z1 = -previous_x1 * sin(data->camera->beta) + coords->z1 * cos(data->camera->beta);
}

void	rotate_z(t_coords *coords, t_fdf *data)
{
	int previous_x;
	int previous_y;
	int previous_x1;
	int previous_y1;

	previous_x = coords->x;
	previous_y = coords->y;
	coords->x = previous_x * cos(data->camera->gamma) - previous_y * sin(data->camera->gamma);
	coords->y = previous_x * sin(data->camera->gamma) + previous_y * cos(data->camera->gamma);
	previous_x1 = coords->x1;
	previous_y1 = coords->y1;
	coords->x1 = previous_x1 * cos(data->camera->gamma) - previous_y1 * sin(data->camera->gamma);
	coords->y1 = previous_x1 * sin(data->camera->gamma) + previous_y1 * cos(data->camera->gamma);
}
