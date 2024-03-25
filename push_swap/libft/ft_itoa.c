/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:06:57 by lglauch           #+#    #+#             */
/*   Updated: 2023/11/02 12:54:40 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	count_digits(long n)
{
	long	digits;

	digits = 0;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static void	int_to_string(long n, long digits, char *str)
{
	str[digits] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	digits--;
	while (n > 0)
	{
		str[digits] = (n % 10) + '0';
		n /= 10;
		digits--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;

	if (n == 0)
		return (ft_strdup("0"));
	digits = count_digits(n);
	if (n < 0)
	{
		digits++;
	}
	str = malloc((sizeof(char) * digits + 1));
	if (!str)
		return (NULL);
	int_to_string(n, digits, str);
	return (str);
}
