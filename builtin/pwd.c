#include "../minishell.h"

int ft_pwd()
{
    char cwd[PATH_MAX];

    if (getcwd(cwd, PATH_MAX))
    {
        write(1,cwd,ft_strlen(cwd));
        write(1,"\n",1);
        return (0);
    }
    //ft_printf("%s\n",ft_get_env("PWD"));
    return (1);
}
