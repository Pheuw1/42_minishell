#include "libft.h"


char **ft_strarrdup(char **strings)
{
    char **ret;
    int n;
    int i;  

    n = 0;
    while (strings[n])
        n++;
<<<<<<< HEAD
    ret = (char **)ft_malloc((n + 1) * sizeof(char *));
=======
    ret = (char **)malloc((n + 1) * sizeof(char *));
>>>>>>> 505d58a9ab97bf70864f107bd619556ef73927c5
    i = -1;
    while (++i < n)
        ret[i] = ft_strdup(strings[i]);
    ret[n] = NULL;
    return (ret);
}