#include "../minishell.h"

char **remove_from_strarr(char **strings, int idx)
{
    int n;
    int i;
    char **ret;

    n = 0;
    while (strings[n])
        n++;
    if (n < idx)
        return (NULL);
    ret = (char **)ft_malloc((n) * sizeof(char *));
    i = -1;
    while (++i < n && i != idx)
            ret[i] = ft_strdup(strings[i]);
    while (++i < n)
            ret[i] = ft_strdup(strings[i]);
    ret[n] = NULL;
    return (ret);
}

int driver_unset(char **env, char *name)
{
    int i;

    i = 0;
    while (env[++i])
        if (!ft_strncmp(env[i], name, ft_strichr(env[i], '=')))
            env = remove_from_strarr(env, i);
    return (0);
}

int ft_unset(char **av, char **env)
{
    int i;

    i = 0;
    while(av[++i])
        driver_unset(env, av[i]);
    return (0);

}
