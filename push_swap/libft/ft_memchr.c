/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:18:54 by lglauch           #+#    #+#             */
/*   Updated: 2023/10/17 18:19:00 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*sn;

	i = 0;
	sn = (unsigned char *)s;
	while (i < n)
	{
		if (sn[i] == (unsigned char)c)
			return (sn + i);
		i++;
	}
	return (NULL);
}
