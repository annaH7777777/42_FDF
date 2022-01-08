/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <annharut@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:16:19 by annharut          #+#    #+#             */
/*   Updated: 2022/01/08 20:32:41 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define WINDOW_HEIGHT 1000
# define WINDOW_WIDTH 1000

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		*data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
}	t_data;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;
}	t_fdf;

typedef struct s_coords
{
	float	x;
	float	y;
	float	x1;
	float	y1;
	int		z;
	int		z1;
}	t_coords;

void	read_file(char *file_name, t_fdf *data);
void	bresenham(t_coords *coords, t_fdf *data);
int		draw(t_fdf *data);
void	terminate(char *s);
void	free_fdf(t_fdf	*data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	clear_color_buffer(t_fdf *data);
void	isometric(t_coords *coords);
void	zoom(t_coords *coords, t_fdf *data);
void	shift(t_coords *coords, t_fdf *data);
float	max_number(float a, float b);
int		rgb(int r, int g, int b);

#endif
