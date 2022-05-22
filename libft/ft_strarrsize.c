#include "libft.h"

int ft_strarrsize(char **strings)
{  
    int i;

    i = 0;
    while(strings[i])
        i++;
    return (i);
}