/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmehdevi <gmehdevi@student.42.fr>          +#+  +:+       +#+        */
/*                          ell                      +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:04:56 by gmehdevi          #+#    #+#             */
/*   Updated: 2021/11/23 20:06:18 by gmehdevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	if (!str)
		return (0);
	while (str && str[n])
		n++;
	return (n);
}
