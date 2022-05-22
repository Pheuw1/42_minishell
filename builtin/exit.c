#include "../minishell.h"

void	ft_exit(char **argv)
{
	ft_error("exit ", NULL, NULL, 0);
	if (ft_strarrsize(argv) > 1)
	{
		g_mini.ret = 1;
		ft_error("minishell: exit:", NULL, "too many arguments", 0);
	}
	else if (argv[1] && ft_str_isnum(argv[1]) == 0)
	{
		g_mini.ret = 255;
        ft_error("minishell: exit:", argv[1],"numeric argument required", 0);
	}
	else if (argv[1])
		g_mini.ret = ft_atoi(argv[1]);
	else
		g_mini.ret = 0;
}