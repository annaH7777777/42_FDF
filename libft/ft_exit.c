
#include "libft.h"

void	ft_exit(char *error)
{
	write(1, error, ft_strlen(error));
	write(1, "\n", 1);
	exit(0);
}