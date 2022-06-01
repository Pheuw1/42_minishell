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

<<<<<<< HEAD
int here_doc(char *dlmtr)
=======
void ft_clearbuffer(char *buffer)
{
    while(*buffer) {
        *buffer = 0;
        buffer++;
    }
}

void here_doc(char *delimiter, int fdin, int fdout)
>>>>>>> 505d58a9ab97bf70864f107bd619556ef73927c5
{
    char    buffer[1024];
    char    *file;
    char    *tmp;
    int     r;
<<<<<<< HEAD
	int 	pip[2];

    r = 0;
    file = NULL;
	pipe(pip);
	while (1)
	{
		ft_memset((void *)buffer, 0, r);
        write(STDOUT,"> ",2);
        while (!ft_strnstr(buffer, "\n", ft_strlen(buffer)))
		{
			ft_memset((void *)buffer, 0, r);
			r = read(STDIN, buffer, 1024);
            buffer[r] = 0;
            if (ft_strncmp(dlmtr, buffer, ft_strlen(dlmtr)-1))
				file = ft_strjoin(file, buffer);
            else
			{
    			write(pip[1], file, ft_strlen(file));
				close(pip[1]);
				return (pip[0]);
			}
        }
	}
}

int		open_in(t_cmd *cmd)
=======
    
    r = 0;
    file = NULL;
	delimiter = ft_strjoin(delimiter,"\n");
    while (ft_strcmp(delimiter, buffer)) {
        write(1,"> ",2);
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
>>>>>>> 505d58a9ab97bf70864f107bd619556ef73927c5
{
    int fd_in;
	int i;

	i = 0;
	fd_in = -1;
<<<<<<< HEAD
	while ((cmd->in && cmd->in[i]))
	{	
		if (fd_in > 0)
			close(fd_in);
		if (cmd->t_in && cmd->t_in[i])
			fd_in = here_doc(cmd->in[i]);
		else
		{	
			fd_in = open(cmd->in[i], O_RDONLY, S_IRWXU);
			if (fd_in < 0)
				return (ft_error("minishell", cmd->in[i], "No such file or directory", -1));
		}
		dup2(fd_in, STDIN);
		i++;
	}
	return (fd_in);
=======
	while (cmd->in[i] || cmd->t_in[i])
	{	
		if (fd_in > 0)
			close(fd_in);
		if (cmd->t_in[i])
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
	}
	return (0);
>>>>>>> 505d58a9ab97bf70864f107bd619556ef73927c5
}

int		open_out(t_cmd *cmd, int fd_to)
{
    int fd_out;
	int i;

	i = 0;
	fd_out = -1;
<<<<<<< HEAD
	while (cmd->out && cmd->out[i])
=======
	while (cmd->out[i] || cmd->t_out[i])
>>>>>>> 505d58a9ab97bf70864f107bd619556ef73927c5
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
<<<<<<< HEAD
	return (fd_out);
=======
	return (0);
>>>>>>> 505d58a9ab97bf70864f107bd619556ef73927c5
}
