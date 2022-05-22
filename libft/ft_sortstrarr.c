#include "libft.h"

char **ft_sortstrarr(char **strings)
{
	int		i;
	int		j;
	int 	n;
    char    *tmp;

	n = 0;
	while (strings[n])
		n++;
	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - 1)
		{
			if (ft_strcmp(strings[j], strings[j + 1]) > 0)
			{
				tmp = strings[j];
                strings[j] = strings[j + 1];
                strings[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (strings);
}
