#include "libft.h"


int len(char **sp)
{
    int i = -1;
    while (sp[++i]) ;
    return i;
}


// main()
// {
//     char **sp = ft_split("1 0 0 0 0 0 0 0 0 0 0 0 0 0 0  0    ", ' ');
//     int l = len(sp);
//     printf("%d\n", l);
//     return 0;
// }