/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:49:14 by dsamain           #+#    #+#             */
/*   Updated: 2022/04/20 20:19:02 by dsamain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

#include <readline/readline.h>
#include <readline/history.h>

void	init_mini(void)
{
	g_mini.garbage = NULL;
	g_mini.env = NULL;
}

//doit quitter les commandes en cours (executer quand ctrl-c est press)
void	ctrl_c(int sig)
{
	printf("ctrl-C\n");
	sig += 1;
}

void	do_nothing(int sig)
{
	printf("ctrl-\\");
	sig += 1;
}

//here to instant free readline :)
char	*ft_readline(char *prompt)
{
	char	*out;
	char	*t;

	t = readline(prompt);
	out = ft_substr(t, 0, ft_strlen(t));
	free(t);
	return (out);
}

int	main(int ac, char **av, char **d_env)
{
	char	*s;
	t_cmd	*cmds;

	ac += 1;
	av += 1;
	signal(SIGINT, ctrl_c);
	signal(SIGQUIT, do_nothing);
	g_mini.env = ft_strs_cpy(d_env);
	//ft_strs_print(mini.env); //print env
	while (1)
	{
		s = ft_readline("\033[34;1;4mminishell$>\033[0m ");
		if (!s)// <=> ctrl-D
			exit(g_mini.ret);
	 	 
		//ft_putstr_fd("here\n",2); 
		if (*s)
		{
			// add_history(s);
			s = expand(s);           
			if (!s)   
				continue ;
			ft_putstr_fd("here\n",2);
			cmds = parse(s);
			if (cmds) 
				print_cmds(cmds);
			ft_putstr_fd("here\n",2);
			execute(cmds, g_mini.env);
		}
	}
	g_clear("");
}
