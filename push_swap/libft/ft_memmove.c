/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:54:34 by lglauch           #+#    #+#             */
/*   Updated: 2023/10/14 15:38:18 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (dst == src)
		return (dst);
	if (dst < src)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		while (len--)
			d[len] = s[len];
	}
	return (dst);
}
// #include <string.h>
// int main() {
//     char str[] = "Hello, World!";
//     char buffer[15]; // Make sure it's large enough to hold the copied data

//     // Using your custom ft_memmove function
//     ft_memmove(buffer, str + 7, 6); // Move "World!" to the buffer

//     // Print the copied data
//     printf("Copied Data: %s\n", buffer); // Output: "World!"

//     return 0;
// }