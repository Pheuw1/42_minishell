#include <stdlib.h>
#include "libft.h"

int		ft_lngh(char **strs, int size, char *sep)
{
	int i;
	int lng;

	i = 0;
	lng = 0;
	while (i < size)
	{
		lng = lng + ft_strlen(strs[i]);
		i++;
	}
	lng = lng + (size - 1) * ft_strlen(sep) + 1;
	return (lng);
}

char	*ft_strcomb(char **strs, char *sep)
{
    int		i;
    int     size;
	char	*str;

    size = 0;
    while (*(strs++))
        size++;
    str = (char *)malloc(sizeof(char) * ft_lngh(strs, size, sep));
    if (!str)
		return (NULL);
	*str = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if (i < size - 1)
			ft_strcat(str, sep);
		i++;
	}
	return (str);
}
