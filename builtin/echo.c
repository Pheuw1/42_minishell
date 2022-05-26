#include "../minishell.h"

int ft_echo(char **av)
{
    int i;
    int n;
    int sz;

    sz = ft_strslen(av);
    n = (sz > 1 && !ft_strcmp(av[1], "-n"));
    i = n;
    while (++i < sz)
    {
        write(1, av[i], ft_strlen(av[i]));
        write(1, " ", i < sz - 1);
    }
    write(1, "\n", !n);
    return (0);
}