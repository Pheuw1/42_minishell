#include "libft.h"

//is strlen if c not found
int ft_strichr(char *string, int c)
{
    int i;

    i = 0;
    while(string[i] && string[i] != c)
        i++;
    return (i);
}