/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:29:31 by lglauch           #+#    #+#             */
/*   Updated: 2024/02/19 16:34:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **stack)
{
	t_stack	*current;
	t_stack	*checker;

	current = *stack;
	while (current != NULL)
	{
		checker = current->next;
		while (checker != NULL)
		{
			if (current->content > checker->content)
			{
				return (0);
			}
			checker = checker->next;
		}
		current = current->next;
	}
	return (1);
}

void	ft_threeargs(t_stack **stack)
{
	int		max;
	t_stack	*current;

	current = *stack;
	max = find_max(stack);
	if (current->content == max)
	{
		ra(stack);
	}
	else if (current->next->content == max)
	{
		rra(stack);
	}
	else if (current->content > current->next->content)
	{
		sa(stack);
	}
}

void	ft_fiveargs(t_stack **stack_a, t_stack **stack_b)
{
	int	min_index;

	min_index = get_min_index(stack_a);
	rotate_until_min(stack_a, min_index, 5);
	pb (stack_a, stack_b);
	min_index = get_min_index(stack_a);
	rotate_until_min(stack_a, min_index, 4);
	pb (stack_a, stack_b);
	while (!is_sorted(stack_a))
	{
		ft_threeargs(stack_a);
	}
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}

int	get_min_index(t_stack **stack)
{
	t_stack	*current;
	int		min_value;
	int		min_index;
	int		i;

	current = *stack;
	min_value = current->content;
	min_index = 0;
	i = 0;
	while (current)
	{
		if (current->content < min_value)
		{
			min_value = current->content;
			min_index = i;
		}
		current = current->next;
		i++;
	}
	return (min_index);
}

void	rotate_until_min(t_stack **stack, int min_index, int size)
{
	int		i;
	//t_stack	*tmp;

	i = 0;
	//tmp = *stack;
	if (min_index <= 2)
	{
		while (i < min_index)
		{
			ra(stack);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < (size - min_index))
		{
			rra(stack);
			i++;
		}
	}
}
