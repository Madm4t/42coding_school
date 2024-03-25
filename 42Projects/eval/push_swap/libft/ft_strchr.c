/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:22:02 by lglauch           #+#    #+#             */
/*   Updated: 2023/11/06 12:50:18 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			j;

	j = 0;
	while (s[j] != 0)
	{
		if (s[j] == (char)c)
		{
			return ((char *)&s[j]);
		}
		j++;
	}
	if ((char)c == 0)
		return ((char *)&s[j]);
	return (NULL);
}
// int main() {
//     const char *str = "Hello, world!";
//     char search_char = 'o';

//     char *result = ft_strchr(str, search_char);
//     if (result != NULL) {
//         printf("Character '%c' found at: %ld\n", search_char, result - str);
//     } else {
//         printf("Character '%c' not found in the string.\n", search_char);
//     }
//     return 0;
// }