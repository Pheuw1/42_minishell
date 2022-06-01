#include "../minishell.h"

<<<<<<< HEAD
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
=======
int driver(char **strings)
{
    while (*strings)
    {
        write(1,*strings,ft_strlen(*strings));
        write(1," ",1);
        strings++;
    }
}

int ft_echo(char **av)
{
    if (ft_strarrsize(av) > 1)
    {
        if (ft_strncmp(av[1],"-n",2))
            driver(&av[2]);
        else
        {
            driver(&av[1]);
            write(1,"\n",1);
        }    
    }
>>>>>>> 505d58a9ab97bf70864f107bd619556ef73927c5
}