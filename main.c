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
	char	*term_type;

	if (!isatty(STDIN_FILENO))
	{	
		g_clear("");
		ft_exit(NULL, 1);
	}
	// increment_shlvl();
	// if (tcgetattr(STDIN_FILENO, &termcaps->old_term) == -1)
	// 	ft_exit(NULL, 1);
	// term_type = ft_get_env("TERM");
	// if (tgetent(termcaps->buffer, term_type) <= 0)
	// 	quit_program(EXIT_FAILURE);
	// else if (!has_capabilities(termcaps))
	// 	quit_program(EXIT_FAILURE);
	free(term_type);
	g_mini.garbage = NULL;
	g_mini.env = NULL;
}

// void	init_termcaps(t_termcaps *termcaps)
// {


// }

//here to instant free readline :)
char *ft_readline(char *prompt)
{
	int		pipefd[2];
	char	out[5000];//limit for a line is 4096ish
	char	*t;
	int 	ret;

	ret = 0;
	pipe(pipefd);
	g_mini.pid = fork();
	if (g_mini.pid)
	{
		close(pipefd[1]);
		ft_bzero(out, 5000);
		waitpid(g_mini.pid, &ret, 0);
		if (status_child(ret) == 1)
			{ft_exit(NULL, 0);}
		read(pipefd[0], out, 5000);
	}
	else 
	{
		close(pipefd[0]);
		signal(SIGINT, SIG_DFL); 
		t = readline(prompt);
		if (!t)
			exit(1);
		write(pipefd[1], t, ft_strlen(t));
		free(t);//shouldn;t need to;
		exit(0);
	}
	return ft_substr(out, 0, ft_strlen(out));
}

//doit quitter les commandes en cours (executer quand ctrl-	c est press)
void	ctrl_c(int sig)
{
	g_mini.sig = sig;
	g_mini.ret = 130;
	kill(g_mini.pid, SIGTERM);
	waitpid(g_mini.pid, NULL, 0);
	g_mini.pid = 0;
	write(1,"\n",1);

	// rl_on_new_line();
	// rl_replace_line("", 0);
	// rl_redisplay();
	// usleep(5);

}

void	ctrl_backslash(int sig)
{
	g_mini.sig = sig;
	g_mini.ret = 131;
}

int	main(int ac, char **av, char **d_env)
{
	char	*s;
	char 	*line;//keep non expanded in history
	t_cmd	*cmds;
	ac += 1;
	av += 1;
	signal(SIGQUIT, ctrl_backslash);
	signal(SIGINT, ctrl_c);
	 // Install the handler
	g_mini.env = ft_strs_cpy(d_env);
	g_mini.exit = 0;
	while (!g_mini.exit)
	{
		s = ft_readline("\033[34;1;4mminishell$>\033[0m ");
		if (!s)// <=> ctrl-D
		{
			g_mini.sig = SIGQUIT;
			g_mini.ret = 131;
			exit(0);
	 	}
		if (s && *s && g_mini.sig != SIGINT && g_mini.sig != SIGQUIT)
		{

			line = expand(s);
			if (!line)
				continue ;
			cmds = parse(line);
			execute_cmds(cmds);
			add_history(s);
		}
		g_mini.sig = 0;
	}
	g_clear("");
	rl_clear_history();
	return (0);
}
