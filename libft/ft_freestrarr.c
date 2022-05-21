/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freepp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmehdevi <gmehdevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 20:46:52 by gmehdevi          #+#    #+#             */
/*   Updated: 2022/01/28 20:56:45 by gmehdevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freestrarr(char **strings)
{
	int		i;

	i = -1;
	while (strings[++i])
	{
		free(strings[i]);
		strings[i] = NULL;
	}
	free(strings);
	strings = NULL;
}
