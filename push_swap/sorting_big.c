/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:46:32 by lglauch           #+#    #+#             */
/*   Updated: 2024/01/30 13:39:44 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_max(t_stack **stack)
{
	t_stack	*current;
	int		index;
	int		max;

	max = get_max(stack);
	current = *stack;
	index = 0;
	while (current && current->content != max)
	{
		current = current->next;
		index++;
	}
	return (index);
}

int	size_stack(t_stack **stack)
{
	t_stack	*current;
	int		size;

	size = 0;
	current = *stack;
	while (current)
	{
		current = current->next;
		size++;
	}
	return (size);
}

int	get_max(t_stack **stack)
{
	t_stack	*current;
	int		max_value;
	int		i;

	current = *stack;
	max_value = current->content;
	i = 0;
	while (current)
	{
		if (current->content > max_value)
		{
			max_value = current->content;
		}
		current = current->next;
		i++;
	}
	return (max_value);
}
