/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:50:08 by lglauch           #+#    #+#             */
/*   Updated: 2023/10/17 16:31:30 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s[i] != 0)
		while (s[i] != 0)
			i++;
	return (i);
}
// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d", ft_strlen("hall232323o"));
// 	return (0);
// }