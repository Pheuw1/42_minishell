/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appends.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:40:15 by dsamain           #+#    #+#             */
/*   Updated: 2022/04/20 18:41:30 by dsamain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	*int_append(int *arr, int val, int sz)
{
	int	*out;
	int	i;

	out = ft_malloc(sizeof(int) * (sz + 1));
	i = -1;
	while (++i < sz)
		out[i] = arr[i];
	out[i] = val;
	return (out);
}

char	*s_append(char *s, char c)
{
	char	*out;
	int		sz;
	int		i;

	sz = ft_strlen(s);
	out = ft_malloc(sizeof(char) * (sz + 2));
	i = 0;
	while (s && s[i])
	{
		out[i] = s[i];
		i++;
	}
	out[i] = c;
	out[i + 1] = 0;
	return (out);
}

char	**strs_append(char **strs, char *s)
{
	char	**out;
	int		sz;

	sz = ft_strslen(strs);
	out = ft_malloc(sizeof(char *) * (sz + 2));
	out[sz] = s;
	out[sz + 1] = NULL;
	while (--sz >= 0)
		out[sz] = strs[sz];
	return (out);
}
