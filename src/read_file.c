/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <annharut@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:21:05 by annharut          #+#    #+#             */
/*   Updated: 2022/01/08 18:23:03 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_matrix(char *file_name, fdf *data)
{
	char	**nums;
	char	*line;
	int		i;
	int		j;
	int		ret;
	int		fd;

	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		terminate("can't open file");
	i = 0;
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (!ret)
		{
			//printf("\nread file ret\n");
			break ;
		}
		nums = ft_split(line, ' ');
		free(line);
		//printf("\nline: %s\n", line);
		j = 0;
		while (nums[j])
		{
			data->z_matrix[i][j] = ft_atoi(nums[j]);
			free(nums[j]);
			j++;
		}
		free(nums);
		i++;
	}
	close(fd);
}

void	read_file(char *file_name, fdf *data)
{
	int		i;
	int		fd;
	int		ret;
	char	*line;
	int		width;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		terminate("can't open file");
	//data->height = get_height(file_name);
	//data->width = get_width(file_name);
	
	
	i = 0;
	height = 0;
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (!ret)
		{
			//printf("\nread file ret\n");
			break ;
		}
		width = ft_strings_count(line, ' ');
		data->width = width;
		height++;
		//printf("\nread file line: %s\n", line);
		//fill_matrix(data->z_matrix[i++], line);
		free(line);
		//printf("\nread file 2\n");
	}
	data->height = height;
	close(fd);

	data->z_matrix = (int **) malloc ((data->height + 1) * sizeof(int *));
	i = 0;
	while (i < data->height)
		data->z_matrix[i++] = (int *) malloc((data->width + 1) * sizeof(int));
	data->z_matrix[i] = NULL;

	fill_matrix(file_name, data);
}
