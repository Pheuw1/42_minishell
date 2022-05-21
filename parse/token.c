/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:26:09 by dsamain           #+#    #+#             */
/*   Updated: 2022/04/20 17:26:09 by dsamain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_sep(char c)
{
	if (c == '|')
		return (PIPE);
	if (c == '\n')
		return (NEW_LINE);
	if (c == '<')
		return (INPUT);
	if (c == '>')
		return (OUTPUT);
	return (0);
}

//erase before push
void	token_print(t_token *root)
{
	int	i;

	if (!root)
		return ;
	i = 0;
	while (root)
	{
		printf("token[%d] :\n	s : %s\n	type : %d\n\n", i, root->str, root->type);
		root = root->next;
		i++;
	}
}

t_token	*set_append_heredoc(t_token *node)
{
	if (!node)
		return (node);
	node = token_back(node);
	while (node->prev)
	{
		if ((node->type == INPUT || node->type == OUTPUT)
			&& node->type == node->prev->type)
		{
			node->prev->str = s_append(node->prev->str, node->str[0]);
			if (!node->prev->str)
				return (NULL);
			if (node->type == INPUT)
				node->prev->type = HEREDOC;
			else
				node->prev->type = APPEND;
			node->prev->next = node->next;
			if (node->next)
				node->next->prev = node->prev;
		}
		node = node->prev;
	}
	return (node);
}

void	parse_quote(t_token *node, char *s, int *i)
{
	char	quote;

	quote = s[*i];
	while (s[++(*i)] && s[*i] != quote)
		node->str = s_append(node->str, s[*i]);
}

int	manage_sep(t_token *token_list, char *s, int *i)
{
	if (s[*i] == '\'' || s[*i] == '\"')
	{
		parse_quote(token_list, s, i);
	}
	else
	{
		token_list->type = is_sep(s[*i]);
		token_list->str = s_append(token_list->str, s[*i]);
	}
	return (1);
}

t_token	*tokenise(char *s)
{
	t_token	*token_list;		
	int		i;

	token_list = NULL;
	i = -1;
	while (s[++i])
	{
		if (token_list == NULL || is_sep(s[i]) || (i > 0 && (is_space(s[i - 1])
					|| is_sep(s[i - 1])) && !is_space(s[i])))
			token_list = token_push_back(token_list);
		if (is_sep(s[i]) || s[i] == '\'' || s[i] == '\"')
		{
			if (!manage_sep(token_list, s, &i))
				return (NULL);
		}
		else if (!is_space(s[i]))
			token_list->str = s_append(token_list->str, s[i]);
	}
	set_append_heredoc(token_list);
	return (token_front(token_list));
}
