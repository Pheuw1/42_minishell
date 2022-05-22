/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:31:16 by dsamain           #+#    #+#             */
/*   Updated: 2022/04/20 19:34:45 by dsamain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*new_token(void)
{
	t_token	*out;

	out = ft_malloc(sizeof(t_token));
	if (!out)
		return (NULL);
	out->next = NULL;
	out->prev = NULL;
	out->str = NULL;
	out->type = ARG;
	return (out);
}

t_token	*token_back(t_token *root)
{
	t_token	*cur;

	if (!root)
		return (NULL);
	cur = root;
	while (cur->next)
		cur = cur->next;
	return (cur);
}

t_token	*token_front(t_token *node)
{
	t_token	*cur;

	if (!node)
		return (NULL);
	cur = node;
	while (cur->prev)
		cur = cur->prev;
	return (cur);
}

t_token	*token_push_back(t_token *root)
{
	t_token	*cur;
	t_token	*back;

	cur = new_token();
	if (!cur)
		return (NULL);
	if (!root)
		return (cur);
	back = token_back(root);
	back->next = cur;
	cur->prev = back;
	return (cur);
}

int	is_space(char c)
{
	if (c == ' ' || c == '	')
		return (1);
	return (0);
}
