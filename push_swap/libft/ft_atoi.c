/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:59:34 by lglauch           #+#    #+#             */
/*   Updated: 2023/11/06 11:21:01 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		j;
	int		sign;
	long	result;

	j = 0;
	sign = 1;
	while (str[j] == '\t' || str[j] == ' ' || str[j] == '\r'
		|| str[j] == '\f' || str[j] == '\n' || str[j] == '\v')
		j++;
	if (str[j] == '+' || str[j] == '-')
	{
		if (str[j] == '-')
			sign = -1;
		j++;
	}
	result = 0;
	while (str[j] != 0 && str[j] >= 48 && str[j] <= 57)
	{
		result = (result * 10) + (str[j] - '0');
		j++;
	}
	return (result * sign);
}

// int	main(void)
// {
// 	const char	str[25] = "--1234535388";

// 	printf("%d", ft_atoi(str));
// }
