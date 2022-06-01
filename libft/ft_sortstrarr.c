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
<<<<<<< HEAD
		j =  i;
		while (j < n)
		{
			if (ft_strcmp(strings[i], strings[j]) > 0)
			{
				tmp = strings[i];
                strings[i] = strings[j];
                strings[j] = tmp;
=======
		j = 0;
		while (j < n - 1)
		{
			if (ft_strcmp(strings[j], strings[j + 1]) > 0)
			{
				tmp = strings[j];
                strings[j] = strings[j + 1];
                strings[j + 1] = tmp;
>>>>>>> 505d58a9ab97bf70864f107bd619556ef73927c5
			}
			j++;
		}
		i++;
	}
<<<<<<< HEAD
	n = -1;
	while (strings[++n])
		ft_printf("%s\n",strings[n]);
=======
>>>>>>> 505d58a9ab97bf70864f107bd619556ef73927c5
	return (strings);
}
