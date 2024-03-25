/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:10:13 by lglauch           #+#    #+#             */
/*   Updated: 2023/11/06 15:01:10 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		sstart;
	int		send;
	char	*ptr;
	int		newlen;
	int		i;

	sstart = 0;
	send = ft_strlen(s1) - 1;
	ptr = (char *)s1;
	if (!s1)
		return (0);
	while (s1[sstart] != 0 && ft_strchr(set, s1[sstart]) != 0)
		sstart++;
	while (send >= sstart && ft_strchr(set, s1[send]) != 0)
		send--;
	newlen = send - sstart + 1;
	ptr = (char *)malloc(newlen + 1);
	if (!ptr)
		return (0);
	i = -1;
	while (++i <= newlen)
		ptr[i] = s1[sstart + i];
	ptr[newlen] = '\0';
	return (ptr);
}
