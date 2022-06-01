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
		j =  i;
		while (j < n)
		{
			if (ft_strcmp(strings[i], strings[j]) > 0)
			{
				tmp = strings[i];
                strings[i] = strings[j];
                strings[j] = tmp;
			}
			j++;
		}
		i++;
	}
	n = -1;
	while (strings[++n])
		ft_printf("%s\n",strings[n]);
	return (strings);
}
