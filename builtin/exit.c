#include "../minishell.h"

int	ft_exit(char **argv, int silent)
{
	if (!silent)
		ft_putstr_fd("exit\n", 1);
	if (ft_strarrsize(argv) > 2)
	{
		g_mini.ret = 1;
		ft_error("minishell: exit:", NULL, "too many arguments", 0);
	}
	else if (ft_strarrsize(argv) == 2 && !ft_str_isnum(argv[1]))
	{
		g_mini.ret = 255;
        ft_error("minishell: exit:", argv[1],"numeric argument required", 0);
	}
	else
	{
		if (argv && argv[1])
			g_mini.ret = ft_atoi(argv[1]);
		else
			g_mini.ret = 0;
		g_mini.exit = 1;
		exit(1);
	}
	g_clear("");
	return (g_mini.ret);
}