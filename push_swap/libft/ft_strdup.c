/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:22:52 by lglauch           #+#    #+#             */
/*   Updated: 2023/11/06 12:52:18 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;

	ptr = (char *)malloc(ft_strlen((s1)) + 1);
	if (!ptr)
		return (0);
	if (ptr != 0)
		ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
	return (ptr);
}

// int main (void)
// {
// 	printf("%s", ft_strdup("hello"));
// 	return (0);
// }
