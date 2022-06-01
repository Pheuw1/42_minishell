#include "../minishell.h"

<<<<<<< HEAD
int	ft_exit(char **argv, int silent)
{
	if (!silent)
		ft_putstr_fd("exit\n", 1);
	if (ft_strarrsize(argv) > 2)
=======
void	ft_exit(char **argv)
{
	ft_error("exit ", NULL, NULL, 0);
	if (ft_strarrsize(argv) > 1)
>>>>>>> 505d58a9ab97bf70864f107bd619556ef73927c5
	{
		g_mini.ret = 1;
		ft_error("minishell: exit:", NULL, "too many arguments", 0);
	}
<<<<<<< HEAD
	else if (ft_strarrsize(argv) == 2 && !ft_str_isnum(argv[1]))
=======
	else if (argv[1] && ft_str_isnum(argv[1]) == 0)
>>>>>>> 505d58a9ab97bf70864f107bd619556ef73927c5
	{
		g_mini.ret = 255;
        ft_error("minishell: exit:", argv[1],"numeric argument required", 0);
	}
<<<<<<< HEAD
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
=======
	else if (argv[1])
		g_mini.ret = ft_atoi(argv[1]);
	else
		g_mini.ret = 0;
>>>>>>> 505d58a9ab97bf70864f107bd619556ef73927c5
}