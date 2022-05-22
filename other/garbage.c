/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:13:43 by dsamain           #+#    #+#             */
/*   Updated: 2022/04/20 20:08:27 by dsamain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_node	*g_new(void *new_elem)
{
	t_node	*out;

	out = malloc(sizeof(t_node));
	if (out)
	{
		out->next = NULL;
		out->elem = new_elem;
	}
	return (out);
}

int	g_push(void *elem)
{
	t_node	*new_node;

	new_node = g_new(elem);
	if (!new_node)
		return (0);
	if (!(g_mini.garbage))
	{
		g_mini.garbage = new_node;
		return (1);
	}
	new_node->next = g_mini.garbage;
	g_mini.garbage = new_node;
	return (1);
}

void	g_print(void)
{
	t_node	*cur;

	if (!g_mini.garbage)
		return ;
	cur = g_mini.garbage;
	while (cur && cur->elem)
	{
		printf("%p ", cur->elem);
		cur = cur->next;
	}
	printf("\n");
}

void	clear_node(t_node *garbage)
{
	if (!garbage)
		return ;
	clear_node(garbage->next);
	if (garbage->elem)
		free(garbage->elem);
	free(garbage);
}

int	g_clear(char *msg)
{
	if (msg)
		ft_putstr_fd(msg, 2);
	if (!g_mini.garbage)
		return (0);
	clear_node(g_mini.garbage);
	g_mini.garbage = NULL;
	return (0);
}
