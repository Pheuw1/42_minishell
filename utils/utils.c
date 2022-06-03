/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:26:40 by dsamain           #+#    #+#             */
/*   Updated: 2022/04/20 18:26:40 by dsamain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_malloc(int size)
{
	void	*out;

	out = malloc(size);
	if (!out || !g_push(out))
	{
		g_clear("malloc error!");
		exit(0);
	}
	return (out);
}

void	cswap(char *a, char *b)
{
	char	t;

	t = *a;
	*a = *b;
	*b = t;
}

char	*ft_itoa(int n)
{
	char	*out;
	int		i;
	int		sz;
	int		neg;

	neg = (n < 0);
	n *= 1 - 2 * (n < 0);
	if (!n)
		return (ft_substr("0", 0, 1));
	out = NULL;
	while (n)
	{
		out = s_append(out, n % 10 + '0');
		n /= 10;
	}
	if (neg)
		out = s_append(out, '-' * neg);
	sz = ft_strlen(out);
	i = -1;
	while (out && ++i < sz / 2)
		cswap(&out[i], &out[sz - i - 1]);
	return (out);
}

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}


int		ft_clstize(t_cmd *cmds)
{
	int	i;

	i = 0;
	while(cmds)
	{
		cmds = cmds->next;
		i++;
	}
	return (i);
}
