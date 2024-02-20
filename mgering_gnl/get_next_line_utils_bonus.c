/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:14:01 by mgering           #+#    #+#             */
/*   Updated: 2024/02/20 16:24:14 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	while ('\0' != *s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!str)
		return (free(s1), NULL);
	while (s1 && '\0' != s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && '\0' != s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	if (s1)
		free(s1);
	return (str);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while ('\0' != s[i])
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*memory_ptr;
	size_t	i;

	i = 0;
	memory_ptr = malloc(nitems * size);
	if (!memory_ptr)
		return (NULL);
	while (i < (nitems * size))
	{
		*((unsigned char *)memory_ptr + i) = '\0';
		i++;
	}
	return (memory_ptr);
}
