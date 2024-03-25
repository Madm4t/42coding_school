/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:44:56 by lglauch           #+#    #+#             */
/*   Updated: 2023/10/17 17:14:24 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (!s1 && !s2 && n == 0)
		return (0);
	while ((((unsigned char *)s1)[i] != 0 || ((unsigned char *)s2)[i] != 0)
		&& i + 1 < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			break ;
		i++;
	}
	if (i < n)
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (0);
}
