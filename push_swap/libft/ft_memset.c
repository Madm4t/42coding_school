/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:03:45 by lglauch           #+#    #+#             */
/*   Updated: 2023/10/17 13:49:17 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	int		i;
	char	*str;

	i = 0;
	str = ptr;
	while ((unsigned) i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (str);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char str[25];
// 	int	c = '1';

// 	printf("%s", ft_memset(str, c, 15));
// }
