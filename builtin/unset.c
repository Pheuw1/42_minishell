#include "../minishell.h"

char *get_name(char *val)
{
    if (ft_strchr(val, '='))
        return(ft_substr(val, 0, ft_strichr(val, '=')));
    return (val);
}


char **remove_from_strarr(char **strings, int idx)
{
    int j;
    int i;
    char **ret;

    if (ft_strarrsize(strings) < idx)
        return (NULL);
    ret = (char **)ft_malloc((ft_strarrsize(strings)) * sizeof(char *));
    i = -1;
    j = -1;
    while (++i < ft_strarrsize(strings))
        if (i != idx)
            ret[++j] = ft_strdup(strings[i]);
    ret[j + 1] = NULL;
    return (ret);
}

int driver_unset(char **env, char *name)
{
    int i;

    i = -1;
    while (g_mini.env[++i])
    {
        if (!ft_strcmp(name, get_name(g_mini.env[i])))
        {  
            g_mini.env = remove_from_strarr(g_mini.env, i);
            return (1);
        }
    }
    return (0);
}

int ft_unset(char **av, char **env)
{
    int i;

    i = 0;
    while(av[++i])
        driver_unset(g_mini.env, av[i]);
    return (0);

}
