#include "libft.h"

void	ft_free_arr(char **arr)
{
	int	i;

	i = ft_char_arr_len(arr) - 1;
	while (i >= 0)
		free(arr[i--]);
}
