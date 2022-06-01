/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmehdevi <gmehdevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:04:48 by gmehdevi          #+#    #+#             */
/*   Updated: 2022/02/24 17:25:55 by gmehdevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1_len;
	unsigned int	s2_len;
	unsigned int	i;
	unsigned int	j;
	char			*out_str;

<<<<<<< HEAD
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	j = 0;
	out_str = (char *)ft_malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!out_str)
		return (NULL);
	while (s1 && s1[i])
=======
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	j = -1;
	out_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!out_str)
		return (NULL);
	while (s1[i])
>>>>>>> 505d58a9ab97bf70864f107bd619556ef73927c5
	{
		out_str[i] = s1[i];
		i++;
	}
<<<<<<< HEAD
	while (s2 && s2[j])
	{
		out_str[i++] = s2[j];
		j++;
	}
=======
	while (s2[++j])
		out_str[i++] = s2[j];
>>>>>>> 505d58a9ab97bf70864f107bd619556ef73927c5
	out_str[i] = '\0';
	return (out_str);
}
