#include "minishell.h"

void		status_child(pid_t pid)
{
	if (WIFEXITED(pid))
		g_mini.ret = WEXITSTATUS(pid);
	if (WIFSIGNALED(pid))
	{
		g_mini.ret = WTERMSIG(pid);
		if (g_mini.ret != 131)
			g_mini.ret += (unsigned char) 128;
	}
}

char *bin_path(char *cmd, char **env)
{
	char	**bins;
	char	*path;
	int		i;

	i = -1;
	path = NULL;
	while (env[++i] && !path)
		path = ft_strnstr(env[i], "PATH=", 5);
	bins = ft_split(path + 5,":");
	cmd = ft_strjoin("/", cmd);
	i =-1;
	while (bins && bins[++i])
	{
		path = ft_strjoin(bins[i],cmd);	
		if (!access(path, F_OK))
		{
			i = -1;
			ft_freestrarr(bins);
			free(cmd);
			return (path);
		}
		free(path);
	}
	return (NULL);
}

int exec_builtin(char **argv)
{
	int ret;

	ret = -255;
	if (!ft_strcmp(argv[0], "echo"))
		ret = ft_echo(argv);	
	else if (!ft_strcmp(argv[0], "unset"))
		ret = ft_unset(argv, g_mini.env);
	else if (!ft_strcmp(argv[0], "export"))
		ret = ft_export(argv, g_mini.env);
	else if (!ft_strcmp(argv[0], "cd"))
		ret = ft_cd(argv);
	else if (!ft_strcmp(argv[0], "pwd"))
		ret = ft_pwd();
	else if (!ft_strcmp(argv[0], "env"))
		ret = ft_env(g_mini.env);
	else if (!ft_strcmp(argv[0], "exit"))
		ret = ft_exit(argv, 0);
	else if ((!ft_strcmp(argv[0], "env")))
		ret = ft_env(g_mini.env);
	else	
		return (ret);
	return (ret);
}


int is_builtin(char **argv)
{
	if ((!ft_strcmp(argv[0], "echo"))
		|| (!ft_strcmp(argv[0], "unset"))
		|| (!ft_strcmp(argv[0], "export"))
		|| (!ft_strcmp(argv[0], "cd"))
		|| (!ft_strcmp(argv[0], "pwd"))
		|| (!ft_strcmp(argv[0], "env"))
		|| (!ft_strcmp(argv[0], "exit"))
		|| (!ft_strcmp(argv[0], "env")))
		return (1);
	return (0);
}
int     exec(t_cmd *cmd, char **env)
{
	char	*path;
	int 	built_in;

	built_in = is_builtin(cmd->arg);
	if (built_in != -255)
	{
		g_mini.ret = built_in;
		return (1);
	}
	if (ft_strchr(cmd->arg[0], '/'))
		path = cmd->arg[0];
	else
    	path = bin_path(cmd->arg[0], env);
	if (!path)
		return (ft_error("access", cmd->arg[0], "couldn't find path to executable", -1));
	if (execve(path, cmd->arg, env) == -1)
        return (ft_error("execve",NULL, "couldnt execute command", -1));
	return (0);
}

void	fork_program(t_cmd *cmd, char **env)
{
	pid_t	pid;
	int		pipefd[2];
	char 	*tmp[10000];

	pipe(pipefd);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
		if (g_mini.fd_in > 0)
			close(g_mini.fd_in);  
		exec_builtin(cmd->arg);
		waitpid(pid, &g_mini.ret, 0);
		status_child(pid);
		if (g_mini.sig == SIGINT || g_mini.sig == SIGQUIT)	
			return ;
		g_mini.fd_in = pipefd[0];
	}
	else 
	{
		if (!cmd->in && g_mini.fd_in > 0)
			dup2(g_mini.fd_in , STDIN);//last out onto current in
		if ((cmd->in && open_in(cmd) == -1) || (cmd->out && open_out(cmd, STDOUT) == -1))
			exit(1);
		if (cmd->next)
			dup2(pipefd[1], STDOUT);
		if (is_builtin(cmd->arg))
			exit(0);
		else if (exec(cmd, env))
			exit(1);
		close(pipefd[0]);
		g_clear("");
	}
}	

int execute(t_cmd *cmds, char **env)
{
	g_mini.fd_in  = -1;
	g_mini.fd_out  = -1;	
	while (cmds)
	{
		fork_program(cmds, env);
		cmds = cmds->next;
	}
	return (0);
}