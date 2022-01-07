#include "fdf.h"

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
	{
		perror("can't open file");
		exit(-1);
	}
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
	{
		perror("can't open file");
		exit(-1);
	}
	get_next_line(fd, &line);
	width = ft_strings_count(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	printf("\nline: %s\n", line);
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, fdf *data)
{
	int		i;
	int		fd;
	int		ret;
	char	*line;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int **) malloc ((data->height + 1) * sizeof(int ));
	i = 0;
	while (i < data->height)
		data->z_matrix[i++] = (int *) malloc((data->width + 1) * sizeof(int));
	data->z_matrix[i] = NULL;
	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		terminate("can't open file");
	i = 0;
	while (1)
	{
		
		ret = get_next_line(fd, &line);
		if (!ret)
		{
			printf("\nread file ret\n");
			break ;
		}
		printf("\nread file line: %s\n", line);
		fill_matrix(data->z_matrix[i++], line);
		//free(line);
		printf("\nread file 2\n");
	}
	close(fd);
}
