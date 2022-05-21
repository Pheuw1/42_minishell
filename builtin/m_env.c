#include "../minishell.h"

int ft_env(char **env)
{
    size_t  i;

    i = 0;
    while (env[i])
    {
        write(1, env[i], ft_strlen(env[i]));
        write(1, "\n", 1);
        i++;
    }
    return (0);
}
