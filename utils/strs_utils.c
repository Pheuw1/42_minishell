/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strs_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:24:52 by dsamain           #+#    #+#             */
/*   Updated: 2022/04/20 19:59:24 by dsamain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strslen(char **strs)
{
	int	i;

	i = 0;
	if (strs)
		while (strs[i])
			i++;
	return (i);
}

char	**ft_strs_cpy(char **strs)
{
	char	**out;
	int		i;
	int		j;

	out = ft_malloc(sizeof(char *) * (ft_strslen(strs) + 1));
	i = -1;
	while (strs && strs[++i])
	{
		j = ft_strlen(strs[i]);
		out[i] = ft_malloc(sizeof(char) * (j + 1));
		out[i][j] = 0;
		while (--j >= 0)
			out[i][j] = strs[i][j];
	}
	out[i] = NULL;
	return (out);
}

void	ft_strs_print(char **strs)
{
	if (!strs)
		printf("(null) ");
	else
	{
		while (*strs)
		{
			printf("|%s |", *strs);
			strs++;
		}
	}
	printf("\n");
}
