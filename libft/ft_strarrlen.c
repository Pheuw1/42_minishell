#include "libft.h"

int ft_strarrlen(char **strings)
{
    int i;

    i = 0;
    while(strings[i])
        i++;
    return (i);
}