/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:00:49 by lglauch           #+#    #+#             */
/*   Updated: 2024/02/05 15:35:56 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_stack_k(t_stack **stack_a, t_stack **stack_k)
{
	t_stack	*current;
	t_stack	*new;

	current = *stack_a;
	*stack_k = NULL;
	while (current)
	{
		new = malloc(sizeof(t_stack));
		if (!new)
			return ;
		new->content = current->content;
		new->next = *stack_k;
		*stack_k = new;
		current = current->next;
	}
}

void	bubble_sort(t_stack **stack_k)
{
	t_stack	*current;
	t_stack	*tmp;
	int		swap;

	swap = 0;
	while (!is_sorted(stack_k))
	{
		current = *stack_k;
		while (current && current->next)
		{
			tmp = current->next;
			if (current->content > tmp->content)
			{
				swap = current->content;
				current->content = tmp->content;
				tmp->content = swap;
			}
			current = current->next;
		}
	}
}

t_stack	*get_block_index(t_stack **stack, int index)
{
	int		i;
	t_stack	*current;

	current = *stack;
	i = 0;
	while (current && i < index)
	{
		current = current->next;
		i++;
	}
	return (current);
}

int	has_smaller_number(t_stack **stack, int index)
{
	t_stack	*current;

	if (!stack)
		return (0);
	current = *stack;
	while (current)
	{
		if (current->content <= index)
			return (1);
		current = current->next;
	}
	return (0);
}

void	sort_blocks(t_stack **stack_a, t_stack **stack_b,
					t_stack **stack_k, int size)
{
	t_stack	*current;
	int		count;

	current = get_block_index(stack_k, size);
	count = 0;
	while (*stack_a && current && has_smaller_number(stack_a, current->content)
		&& count < size)
	{
		if ((*stack_a)->content <= current->content)
		{
			pb(stack_a, stack_b);
			count++;
		}
		else
		{
			ra(stack_a);
		}
	}
}
