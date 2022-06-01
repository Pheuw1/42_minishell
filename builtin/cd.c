#include "../minishell.h"


void update_env_pwd(char **env, char *new_pwd)
{
    char *args_pwd[3];
    char *args_oldpwd[3];
    int i;

    i = -1;
    while (env[++i])
        if (!ft_strncmp("PWD", env[i], 3))
            break ;
    driver_unset(env, "OLDPWD");
    driver_unset(env, "PWD");
    args_oldpwd[0] = "export";
    args_oldpwd[1] = ft_strjoin("OLDPWD=", get_val_env(env, "PWD"));
    args_oldpwd[2] = NULL;
    args_pwd[0] = "export"; 
    args_pwd[1] = ft_strjoin("PWD=", new_pwd);
    args_pwd[2] = NULL;
    ft_export(args_pwd, env);
    ft_export(args_oldpwd , env);
}

//getcwd,chdir
int driver_cd(char *path)
{
    char    *abs_path;
    char    *tmp;
    int     ret;

    ret = -1;
    if (!ft_strncmp(path, "/", 1))
    {
        ret = chdir(path); 
        update_env_pwd(g_mini.env, path);
    }
    else
    {
        if (!ft_strncmp(path, "./", 2))
            path += 2;
        tmp = ft_strjoin(get_val_env(g_mini.env, "PWD"),"/");
        abs_path = ft_strjoin(tmp, path);
        ret = chdir(abs_path);
        update_env_pwd(g_mini.env, abs_path);
        free(tmp);
        free(abs_path);
    }
    return (ret);
}

int ft_cd(char **av)
{
    char *msg;

    if (ft_strarrsize(av) > 2)
        return (ft_error("minishell : cd", 0, "too many arguments", 1));
    if (ft_strarrsize(av) == 2)
        if (driver_cd(av[1]))
            return (ft_error("minishell : cd", av[1], "No such file or directory", 1));
    return (0);
}