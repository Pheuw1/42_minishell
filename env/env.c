/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:46:19 by dsamain           #+#    #+#             */
/*   Updated: 2022/04/20 20:14:17 by dsamain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	shell_env(char **def_env)
{
	g_mini.env = ft_strs_cpy(def_env);
	ft_strs_print(g_mini.env);
	return (1);
}

char	*ft_get_env(char *key)
{
	char	*out;
	int		i;
	int		j;

	key = s_append(key, '=');
	out = ft_substr("", 0, 0);
	if (!g_mini.env || !key)
		return (out);
	i = 0;
	while (g_mini.env[i])
	{
		if (!ft_strncmp(g_mini.env[i], key, ft_strlen(key)))
		{
			j = 0;
			while (g_mini.env[i][j] && g_mini.env[i][j] != '=')
				j++;
			out = ft_substr(g_mini.env[i], j + 1, INF);
			return (out);
		}
		i++;
	}
	return (out);
}

char	*expand_un_truc(char *s, char *out, int *i)
{
	char	*cur;
	int		j;

	j = *i + 1;
	while (s[j] && !is_sep(s[j]) && !is_space(s[j])
		&& s[j] != '$' && s[j] != '\'' && s[j] != '\"')
		j++;
	cur = ft_substr(s, *i + 1, j - *i -1);
	if (!ft_strncmp(cur, "?", 1))
		out = s_append_str(out, ft_itoa(g_mini.ret));
	else if (!(*cur) && s[j] != '\'' && s[j] != '\"')
		out = s_append(out, '$');
	else
		out = s_append_str(out, ft_get_env(cur));
	*i = j - 1;
	return (out);
}

char	*expand(char *s)
{
	char	*out;
	char	quoted;
	int		i;

	out = NULL;
	quoted = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == '\'' || s[i] == '\"')
			quoted = s[i] * !quoted;
		if (s[i] == '$' && quoted != '\'')
			out = expand_un_truc(s, out, &i);
		else
			out = s_append(out, s[i]) ;
	}
	return (out);
}
