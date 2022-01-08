/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <annharut@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:21:05 by annharut          #+#    #+#             */
/*   Updated: 2022/01/08 20:35:08 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_matrix(char *file_name, t_fdf *data, int ret)
{
	char	**nums;
	char	*line;
	int		i;
	int		j;
	int		fd;

	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (!ret)
			break ;
		nums = ft_split(line, ' ');
		free(line);
		j = -1;
		while (nums[++j])
		{
			data->z_matrix[i][j] = ft_atoi(nums[j]);
			free(nums[j]);
		}
		free(nums);
		i++;
	}
	close(fd);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		i;
	int		fd;
	int		ret;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		terminate("can't open file");
	data->height = 0;
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (!ret)
			break ;
		data->width = ft_strings_count(line, ' ');
		data->height++;
		free(line);
	}
	close(fd);
	data->z_matrix = (int **) malloc ((data->height + 1) * sizeof(int *));
	i = 0;
	while (i < data->height)
		data->z_matrix[i++] = (int *) malloc((data->width + 1) * sizeof(int));
	data->z_matrix[i] = NULL;
	fill_matrix(file_name, data, ret);
}
