/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmehdevi <gmehdevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:17:47 by gmehdevi          #+#    #+#             */
/*   Updated: 2022/02/24 17:22:56 by gmehdevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_error(char *prog, char *value, char *msg, int ret)
{
	if (prog)
	{
		write(2, prog, ft_strlen(prog));
		write(2, " : ", 3);
	}
	if (value)
	{
			write(2, value, ft_strlen(value));
			write(2, " : ", 3);	
	}
	if (msg)
	{
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	}
	return (ret);
}
