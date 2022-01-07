#include "fdf.h"

int get_height(char *file_name)
{
    char *line;
    int fd;
    int height;

    if((fd = open(file_name, O_RDONLY, 0)) == -1)
		return (-1);
    height = 0;
    while(get_next_line(fd, &line))
    {
        height++;
        free(line);
    }
    close(fd);
    return(height);
}

int get_width(char *file_name)
{
	int width;
	int fd;
	char *line;

	if((fd = open(file_name, O_RDONLY, 0)) == -1)
		return (-1);
	get_next_line(fd, &line);
	width = ft_strings_count(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void fill_matrix(int *z_line, char *line)
{
	char **nums;
	int i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		// printf("\nnums[%d]:  %s\n", i, nums[i]);
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void read_file(char *file_name, fdf *data)
{
    int i;
	int fd;
	char *line;
	
	
	printf("\nread file start\n");
	data->height = get_height(file_name);
    data->width = get_width(file_name);
	//printf("\nheight: %d\twidth: %d\n", data->height, data->width);
	data->z_matrix = (int**) ft_calloc((data->height + 1), sizeof(int*));
	i = 0;
	while(i < data->height)
		data->z_matrix[i++] = (int*) ft_calloc ((data->width + 1), sizeof(int));
	data->z_matrix[i] = NULL;
	if((fd = open(file_name, O_RDONLY, 0)) == -1)
		return ;
	printf("\nread file fd: %d\n", fd);
	i = 0;
	while(1)
	{
		int ret = get_next_line(fd, &line);
		if (!ret)
			break ;
		//printf("line: %s\n", line);
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	//printf("\nread file 1\n");
	printf("\nread file finish\n");
	close(fd);
}
