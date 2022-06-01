#include "../minishell.h"

char **add_to_strarr(char **strings, char *s)
{
	int i;
	char **ret;

	i = 0;
	while (strings[i])
		i++;
<<<<<<< HEAD
	ret = (char **)ft_malloc((i + 2) * sizeof(char *));
=======
	ret = (char **)malloc((i + 2) * sizeof(char *));
>>>>>>> 505d58a9ab97bf70864f107bd619556ef73927c5
	i = -1;
	while (strings[++i])
		ret[i] = ft_strdup(strings[i]);
	ret[i] = ft_strdup(s);
	ret[i + 1] = NULL; 
<<<<<<< HEAD
=======
	ft_freestrarr(strings);
>>>>>>> 505d58a9ab97bf70864f107bd619556ef73927c5
	return (ret);
}

int		is_valid_env(const char *var)
{
	int		i;

	if (ft_isdigit(var[i]))
		return (0);
	i = -1;
<<<<<<< HEAD
	while (var[++i] && var[i] != '=') 
		if (!ft_isalnum(var[i]) && var[i] != '_')
			return (0);
	if (i < 1)
		return (0);
=======
	while (var[++i]) 
		if (!ft_isalnum(var[i]) || var[i] != '_')
			return (0);
>>>>>>> 505d58a9ab97bf70864f107bd619556ef73927c5
	return (1);
}

char		*get_val_env(char **m_env, char *name)
{
	int	i;

	i = -1;
	while (m_env[++i])
		if (!ft_strncmp(name, m_env[i],ft_strlen(name)))
			return (ft_strrchr(m_env[i], '=') + 1);
	return (NULL);
}

void print_sorted_env(char **env)
{

	char 	**dup;
	int		i;
	int		j;

	dup = ft_sortstrarr(ft_strarrdup(env));
	i = 0;
	while (dup[i])
	{
<<<<<<< HEAD
		j = 0;
		if (ft_strncmp("_", dup[i], ft_strichr(dup[i],'=')))
		{	
			ft_printf("declare -x ");
			while (dup[i][j] && dup[i][j] != '=')
				ft_printf("%c", dup[i][j++]);
			if (ft_strchr(dup[i], '='))
			{
				ft_printf("=");
				ft_printf("\"%s\"", ft_strchr(dup[i], '=') + 1);
			}
			ft_printf("\n");
		}
		i++;
	}
	ft_freestrarr(dup);
=======
		ft_printf("declare -x ");
		if (!ft_strchr(dup[i], '='))	
			ft_printf("%s", dup[i]);
		else
		{
			while (dup[i][j] && dup[i][j] != '=')
				ft_printf("%c", dup[i][j]);
			ft_printf("\"%s\"", ft_strchr(dup[i], '='));
		}
	}
>>>>>>> 505d58a9ab97bf70864f107bd619556ef73927c5
}

int			ft_export(char **args, char **env)
{
	int i;
	int j;

	i = 0;
	if (!args[1])
		print_sorted_env(env);
	else
		while (args[++i])
		{
			if (is_valid_env(args[i]))
			{
				j = 0;
<<<<<<< HEAD
				driver_unset(env, args[i]);
				g_mini.env = add_to_strarr(env, args[i]);
			}
			else
				return (ft_error("bash: export", args[i], "not a valid identifier", -1));
=======
				while (env[++j])
					if (!ft_strncmp(args[i], env[j], ft_strichr(env[i], '=')))
						driver_unset(env, args[i]);
				add_to_strarr(env, args[i]);
			}
			else
				ft_error("bash: export", args[i], "not a valid identifier", 0);

>>>>>>> 505d58a9ab97bf70864f107bd619556ef73927c5
		}
	return (0);
}
