/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:46:24 by lglauch           #+#    #+#             */
/*   Updated: 2023/10/20 16:08:51 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	total_len(char const *s1, char const *s2)
{
	int		total_len;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	return (total_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	ptr = (char *)malloc(total_len(s1, s2) + 1);
	if (ptr)
	{
		while (i < ft_strlen(s1))
		{
			ptr[i] = s1[i];
			i++;
		}
		while (j < ft_strlen(s2))
		{
			ptr[i + j] = s2[j];
			j++;
		}
		ptr[i + j] = '\0';
	}
	else
		return (NULL);
	return (ptr);
}
