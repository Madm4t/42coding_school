/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:15:49 by lglauch           #+#    #+#             */
/*   Updated: 2023/11/06 11:28:32 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

// #include <string.h>
// int main(void) {
//     char myString[20] = "hello";
//     int n = 10;

//     // Call your custom bzero function
//     ft_bzero(myString, n);

//     // Output the modified string
//     printf("Modified string: %s\n", myString);

//     // Optionally, compare the result with the standard memset function
//     char standardString[20] = "hello";
//     memset(standardString, 0, n);
//     printf("Standard memset result: %s\n", standardString);

//     return 0; // Indicates successful program execution
// }
