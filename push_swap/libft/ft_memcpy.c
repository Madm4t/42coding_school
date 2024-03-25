/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:33:52 by lglauch           #+#    #+#             */
/*   Updated: 2023/11/06 11:45:00 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*source;

	i = 0;
	dest = dst;
	source = src;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}

// #include <string.h>

// int main(void) 
// {
//     char source[] = "Hello, World!";
//     char destination[20];
//     size_t n = 5;

//     memcpy(destination, source, n);

//     printf("Source: %s\n", source);
//     printf("Destination: %s\n", destination);

//     return 0;
// }
