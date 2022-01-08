#ifndef FDF_H
# define FDF_H

#include "libft.h"
#include "get_next_line.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

#define WINDOW_HEIGHT 2000
#define WINDOW_WIDTH 2000

typedef struct s_data
{
  void *img;
  char *addr;
  int *data;
  int bits_per_pixel;
  int line_length;
  int endian;
  int		img_width;
	int		img_height;
} t_data;

typedef struct
{
    int width;
    int height;
    int **z_matrix;
    int zoom;
    int color;
    int shift_x;
    int shift_y;

    void *mlx_ptr;
    void *win_ptr;
    t_data img;
}   fdf;



void    read_file(char *file_name, fdf *data);
void    bresenham(float x, float y, float x1, float y1, fdf *data);
int     draw(fdf *data);
void    terminate(char *s);
void    free_fdf(fdf	*data);

#endif
