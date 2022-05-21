/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:24:40 by dsamain           #+#    #+#             */
/*   Updated: 2022/04/20 17:24:40 by dsamain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_error(t_token *token_list, char *s)
{
	int	q_cnt;
	int	dq_cnt;

	q_cnt = 0;
	dq_cnt = 0;
	while (*s)
	{
		q_cnt += (*s == '\'' && !(dq_cnt % 2));
		dq_cnt += (*s == '\"' && !(q_cnt % 2));
		s++;
	}
	if (token_list && token_list->type == PIPE)
		return (1);
	while (token_list)
	{
		if ((token_list->type != ARG && token_list->type != PIPE)
			&& (!token_list->next || token_list->next->type != ARG))
			return (1);
		if (token_list->type == PIPE
			&& (!token_list->next || token_list->next->type == PIPE))
			return (1);
		token_list = token_list->next;
	}
	return (q_cnt % 2 || dq_cnt % 2);
}

void	parse_cmds(t_token *token_list, t_cmd *cmds)
{
	while (token_list)
	{
		if (token_list->type == PIPE)
			cmds = cmds->next;
		else if (token_list->type == INPUT || token_list->type == HEREDOC)
		{
			cmds->in = strs_append(cmds->in, token_list->next->str);
			token_list->next = token_list->next->next;
			cmds->t_in = int_append(cmds->t_in, (token_list->type == HEREDOC),
					ft_strslen(cmds->in) - 1);
		}
		else if (token_list->type == OUTPUT || token_list->type == APPEND)
		{
			cmds->out = strs_append(cmds->out, token_list->next->str);
			token_list->next = token_list->next->next;
			cmds->t_out = int_append(cmds->t_out, (token_list->type == APPEND),
					ft_strslen(cmds->out) - 1);
		}
		else
			cmds->arg = strs_append(cmds->arg, token_list->str);
		token_list = token_list->next;
	}
}

t_cmd	*parse(char *s)
{
	t_token	*token_list;
	t_cmd	*cmds;
	int		sz;

	token_list = tokenise(s);
	if (check_error(token_list, s))
	{
		g_mini.ret = 2;
		ft_putstr_fd("\xE2\x98\xA0", 2);
		ft_putstr_fd("  \033[31;1;mSyntax error\033[0m\n", 2);
		return (NULL);
	}
	sz = get_cmds_size(token_list);
	cmds = init_cmds(sz);
	parse_cmds(token_list, cmds);
	return (cmds);
}
