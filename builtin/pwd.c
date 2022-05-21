#include "../minishell.h"

int ft_pwd()
{
    char cwd[PATH_MAX];

    if (getcwd(cwd, PATH_MAX))
    {
        write(1,cwd,ft_strlen(cwd));
        return (0);
    }
    return (1);
}
