#include "../minishell.h"

char **add_to_strarr(char **strings, char *s)
{
	int i;
	char **ret;

	i = 0;
	while (strings[i])
		i++;
	ret = (char **)malloc((i + 2) * sizeof(char *));
	i = -1;
	while (strings[++i])
		ret[i] = ft_strdup(strings[i]);
	ret[i] = ft_strdup(s);
	ret[i + 1] = NULL; 
	ft_freestrarr(strings);
	return (ret);
}

int		is_valid_env(const char *var)
{
	int		i;

	if (ft_isdigit(var[i]))
		return (0);
	i = -1;
	while (var[++i]) 
		if (!ft_isalnum(var[i]) || var[i] != '_')
			return (0);
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
				while (env[++j])
					if (!ft_strncmp(args[i], env[j], ft_strichr(env[i], '=')))
						driver_unset(env, args[i]);
				add_to_strarr(env, args[i]);
			}
			else
				ft_error("bash: export", args[i], "not a valid identifier", 0);

		}
	return (0);
}
