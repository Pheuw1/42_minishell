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
//exit doesnt work from fork anymore?

//ctrl-c doesnt give back prompt

//ctrl-d needs to be pressed twice if command wanst found
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

//doit quitter les commandes en cours (executer quand ctrl-c est press)
void	ctrl_c(int sig)
{
	int p[2];

	pipe(p);
	g_mini.sig = sig;
	g_mini.ret = 130;
}

void	ctrl_backslash(int sig)
{
	g_mini.sig = sig;
	g_mini.ret = 131;
}

int	main(int ac, char **av, char **d_env)
{
	char	*s;
	t_cmd	*cmds;

	ac += 1;
	av += 1;
	signal(SIGINT, ctrl_c);
	signal(SIGQUIT, ctrl_backslash);
	g_mini.env = ft_strs_cpy(d_env);\
	g_mini.exit = 0;
	while (!g_mini.exit)
	{
		s = ft_readline("\033[34;1;4mminishell$>\033[0m ");
		if (!s)// <=> ctrl-D
		{
			g_mini.sig = SIGQUIT;
			g_mini.ret = 131;
			ft_exit(NULL, 0);
	 	}
		if (s && *s && g_mini.sig != SIGINT && g_mini.sig != SIGQUIT)
		{
			add_history(s);
			s = expand(s);           
			if (!s)   
				continue ;
			cmds = parse(s);
			if (cmds)
				print_cmds(cmds);
			//handle ctrl c somehow
			//behaviour is different during execution
			// cant just rewrite prompt
			execute(cmds, g_mini.env);
		}
		g_mini.sig = 0;
	}
	g_clear("");
}
