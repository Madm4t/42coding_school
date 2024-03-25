/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:30:16 by lglauch           #+#    #+#             */
/*   Updated: 2023/11/06 13:15:39 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dlen;
	size_t		slen;
	size_t		i;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = 0;
	if (dst == NULL || src == NULL)
		return (dlen);
	if (size <= dlen)
	{
		slen = slen + size;
	}
	else
		slen = slen + dlen;
	while (src[i] != 0 && size > (dlen + i + 1))
	{
		dst[dlen + i] = src[i];
		i++;
	}
	if (dlen + i < size)
		dst[dlen + i] = '\0';
	return (slen);
}

// #include <stdio.h>
// int main() {
//     char dest[20] = "Hello, ";
//     char src[] = "World123!";
//     size_t result;

//     // Call your ft_strlcat function
//     result = ft_strlcat(dest, src, sizeof(dest));

//     printf("Concatenated string: %s\n", dest);
//     printf("Total length: %zu\n", result);

//     return 0;
// }