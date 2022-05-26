#include "minishell.h"

int get_path_perm(char *path)
{
	int perm;

	perm = 0;
 	if (access(path, F_OK))
		return (-1);
  	else {
    	if (!access(path, R_OK))
			perm |= 4;
    	if (!access(path, W_OK))
			perm |= 2;
    	if (!access(path, X_OK))
			perm |= 1;
		return (perm);
	}
}

void ft_clearbuffer(char *buffer)
{
    while(*buffer) {
        *buffer = 0;
        buffer++;
    }
}

void here_doc(char *delimiter, int fdin, int fdout)
{
    char    buffer[1024];
    char    *file;
    char    *tmp;
    int     r;

    r = 0;
    file = NULL;
	delimiter = ft_strjoin(delimiter,"\n");
    while (ft_strcmp(delimiter, buffer)) {
        write(fdout,"> ",2);
        while (!ft_strnstr(buffer, "\n", ft_strlen(buffer))) {
			ft_memset((void *)buffer, 0, r);
            r = read(fdin, buffer, 1024);
            buffer[r] = 0;
            if (ft_strcmp(delimiter, buffer))
                tmp = ft_strjoin(file, buffer);
            else
                break;
            free(file);
            file = tmp;
        }
    }
    write(fdout, file, ft_strlen(file));
    free(delimiter);
    free(file);
}

int		open_in(t_cmd *cmd, int fd_to)
{
    int fd_in;
	int i;

	i = 0;
	fd_in = -1;
	while ((cmd->in && cmd->in[i]) || (cmd->t_in && cmd->t_in[i]))
	{	
		if (fd_in > 0)
			close(fd_in);
		if (cmd->t_in && cmd->t_in[i])
		{
			fd_in = -1;
			here_doc(cmd->in[i], STDIN, fd_to);
		}
		else
			fd_in = open(cmd->in[i], O_RDONLY, S_IRWXU);
		if (fd_in < 0)
			return (ft_error("minishell", cmd->in[i], "No such file or directory", -1));
		else
			dup2(fd_in, fd_to);
		i++;
	}
	return (0);
}

int		open_out(t_cmd *cmd, int fd_to)
{
    int fd_out;
	int i;

	i = 0;
	fd_out = -1;
	while ( (cmd->out && cmd->out[i]) ||  (cmd->t_out && cmd->t_out[i]))
	{	
		if (fd_out > 0)
			close(fd_out);
		if (cmd->t_out[i])
			fd_out = open(cmd->out[i], O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
		else
			fd_out = open(cmd->out[i], O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
		if (fd_out < 0)
			return (ft_error("minishell", cmd->out[i], "No such file or directory", -1));
		else
			dup2(fd_out, fd_to);
		i++;
	}
	return (0);
}
