#include "libft.h"

int ft_abs(int n)
{
	return (n*(((n>0)<<1)-1));
}

int my_abs(int x)
{
    int y = (x >> 31);
    return (x ^ y) - y;
}	