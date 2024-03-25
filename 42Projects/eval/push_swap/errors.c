/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra <intra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:31:56 by lglauch           #+#    #+#             */
/*   Updated: 2024/01/22 15:59:29 by intra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (number[i] == '-')
		{
			i++;
			if (ft_isdigit(number[i]) == 0 || number[i] == '\0')
			{
				return (0);
			}
		}
		else if (ft_isdigit(number[i]) == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_duplicates(t_stack **stack)
{
	t_stack	*current;
	t_stack	*checker;

	current = *stack;
	while (current != NULL)
	{
		checker = current->next;
		while (checker != NULL)
		{
			if (current->content == checker->content)
				return (0);
			checker = checker->next;
		}
		current = current->next;
	}
	return (1);
}

int	check_size(char *number)
{
	int	len;

	len = ft_strlen(number);
	if (len > 11)
		return (0);
	if (len == 11 && number[0] != '-')
		return (0);
	if (len == 11 && number[0] == '-' && ft_strcmp(number, "-2147483648") > 0)
		return (0);
	if (len == 10 && number[0] != '-' && ft_strcmp(number, "2147483647") > 0)
		return (0);
	return (1);
}

void	stack_push(t_stack **stack, int content)
{
	t_stack	*new;

	new = lstnew(content);
	if (new == NULL)
		return ;
	lstadd_back(stack, new);
}
