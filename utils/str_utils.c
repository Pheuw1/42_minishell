/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:24:11 by dsamain           #+#    #+#             */
/*   Updated: 2022/04/20 20:15:15 by dsamain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*s_append_str(char *s1, char *s2)
{
	int	i;

	if (!s2)
		return (s1);
	i = -1;
	while (s2[++i])
		s1 = s_append(s1, s2[i]);
	return (s1);
}

char	*ft_substr(char *s, unsigned int start, unsigned int n)
{
	char	*out;
	int		i;

	if (!s)
		return (NULL);
	if ((int)start >= ft_strlen(s))
		n = 0;
	out = ft_malloc(sizeof(char) * (n + 1));
	i = 0;
	while (i < (int)n && s[start + i])
	{
		out[i] = s[start + i];
		i++;
	}
	out[i] = 0;
	return (out);
}
