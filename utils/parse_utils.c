/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:58:19 by dsamain           #+#    #+#             */
/*   Updated: 2022/04/20 19:58:20 by dsamain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_cmds_size(t_token *token_list)
{
	t_token	*token;
	int		sz;

	sz = 0;
	token = token_list;
	while (token)
	{
		sz += (token->type == PIPE);
		token = token->next;
	}
	return (sz + 1);
}

t_cmd	*new_cmd(void)
{
	t_cmd	*out;

	out = ft_malloc(sizeof(t_cmd) + 10);
	out->arg = NULL;
	out->in = NULL;
	out->t_in = NULL;
	out->t_out = NULL;
	out->out = NULL;
	out->next = NULL;
	return (out);
}

t_cmd	*init_cmds(int sz)
{
	t_cmd	*out;
	t_cmd	*cur;
	int		i;

	out = new_cmd();
	cur = out;
	i = 0;
	while (++i < sz)
	{
		cur->next = new_cmd();
		cur = cur->next;
	}
	return (out);
}

void	print_cmds(t_cmd *cmds)
{
	int	i;
	int	j;

	i = 0;
	printf("\n		\033[38;5;203;1;4mCommands list\033[0m\n");
	while (cmds)
	{
		printf("cmds[%d]:\n	ARG: ", i++);
		ft_strs_print(cmds->arg);
		if (cmds->in)
			printf("	IN:  ");
		j = -1;
		while (cmds->in && cmds->in[++j])
			printf("%s%c%c%c ", cmds->in[j], cmds->t_in[j]
				* '(', cmds->t_in[j] * 'h', cmds->t_in[j] * ')');
		if (cmds->out)
			printf("\n	OUT: ");
		j = -1;
		while (cmds->out && cmds->out[++j])
			printf("%s%c%c%c ", cmds->out[j], cmds->t_out[j]
				* '(', cmds->t_out[j] * 'a', cmds->t_out[j] * ')');
		printf("\n");
	cmds = cmds->next;
	}
}
