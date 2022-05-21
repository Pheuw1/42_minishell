#include "../minishell.h"

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
}