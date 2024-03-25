/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:02:55 by lglauch           #+#    #+#             */
/*   Updated: 2024/02/05 15:33:53 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_stack **stack_a, t_stack **stack_b)
{
	int	index;
	int	size;
	int	max;

	while (*stack_b)
	{
		size = size_stack(stack_b);
		max = get_max(stack_b);
		index = get_index_max(stack_b);
		if (index < size / 2)
		{
			while ((*stack_b)->content != max)
			{
				rb(stack_b);
			}
		}
		else
		{
			while ((*stack_b)->content != max)
			{
				rrb(stack_b);
			}
		}
		pa(stack_b, stack_a);
	}
}

void	sort_all(t_stack **stack_a, t_stack **stack_b, t_stack **stack_k)
{
	int		size;
	int		prev_size;
	int		now_size;
	int		num;

	prev_size = 0;
	now_size = 1;
	num = 0;
	make_stack_k(stack_a, stack_k);
	bubble_sort(stack_k);
	size = size_stack(stack_a);
	while (*stack_a && prev_size != now_size)
	{
		num += size;
		prev_size = size_stack(stack_a);
		if (size <= 100)
			sort_blocks(stack_a, stack_b, stack_k, num / 4);
		else
			sort_blocks(stack_a, stack_b, stack_k, num / 8);
		now_size = size_stack(stack_a);
	}
	while (*stack_a)
		pb(stack_a, stack_b);
	push_back(stack_a, stack_b);
}

t_stack	*push_swap(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*stack_k;
	int		arg_count;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	arg_count = check_args(argc, argv, &stack_a);
	if (is_sorted(&stack_a) == 1)
		return (0);
	while (arg_count == 3 && !is_sorted(&stack_a))
		ft_threeargs(&stack_a);
	while (arg_count == 5 && !is_sorted(&stack_a))
		ft_fiveargs(&stack_a, &stack_b);
	while (arg_count > 5 && !is_sorted(&stack_a))
		sort_all(&stack_a, &stack_b, &stack_k);
	free_stack(stack_a);
	free_stack(stack_b);
	free_stack(stack_k);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
	return (0);
}
