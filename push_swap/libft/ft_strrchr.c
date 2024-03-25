/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:14:39 by lglauch           #+#    #+#             */
/*   Updated: 2023/10/17 15:07:41 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			j;

	j = ft_strlen((char *)s);
	while (j >= 0)
	{
		if (s[j] == (char)c)
		{
			return ((char *)&s[j]);
		}
		j--;
	}
	if ((char)c == 0)
		return ((char *)&s[j]);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int main ()
// {
//   char str[] = "This is a sample string";
//   char *pch;
//   pch = ft_strrchr(str,'s');
//   printf ("Last occurence of 's' found at %ld \n",pch-str+1);
//   return 0;
// }