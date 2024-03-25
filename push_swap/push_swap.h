/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:34:57 by lglauch           #+#    #+#             */
/*   Updated: 2024/02/01 15:44:27 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

void	sort_alg(t_stack **stack_a, t_stack **stack_b);
int		is_empty(t_stack *stack);

int		check_duplicates(t_stack **stack);
int		check_digit(char *number);
int		check_size(char *number);
void	stack_push(t_stack **stack, int content);
int		check_args(int argc, char **argv, t_stack **stack);
int		split_args_number(char **split_args, t_stack **stack);
void	ft_threeargs(t_stack **stack);
void	ft_fiveargs(t_stack **stack_a, t_stack **stack_b);
void	free_stack(t_stack *stack);
int		find_max(t_stack **stack);
int		ft_strcmp(const char *s1, const char *s2);
void	lstadd_back(t_stack **lst, t_stack *n);
t_stack	*lstnew(int content);

void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_a);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	reverserotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

int		is_sorted(t_stack **stack);
int		get_min_index(t_stack **stack);
int		get_max(t_stack **stack);
void	rotate_until_min(t_stack **stack, int min_index, int size);
void	sorting_big(t_stack **stack_a, t_stack **stack_b);
void	make_stack_k(t_stack **stack_a, t_stack **stack_k);
void	bubble_sort(t_stack **stack_k);
int		size_stack(t_stack **stack);
int		get_index_max(t_stack **stack);
void	sort_all(t_stack **stack_a, t_stack **stack_b, t_stack **stack_k);
void	sort_blocks(t_stack **stack_a, t_stack **stack_b, \
t_stack **stack_k, int size);

#endif