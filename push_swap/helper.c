/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:23:47 by lglauch           #+#    #+#             */
/*   Updated: 2024/02/01 15:14:04 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstnew(int content)
{
	t_stack	*str;

	str = malloc(sizeof(t_stack));
	if (!str)
		return (0);
	str->content = content;
	str->next = NULL;
	return (str);
}

void	lstadd_back(t_stack **lst, t_stack *n)
{
	t_stack	*current;

	current = NULL;
	if (!n || !lst)
		return ;
	if (*lst == NULL)
	{
		*lst = n;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = n;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t		i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	while ((((unsigned char *)s1)[i] != 0 || ((unsigned char *)s2)[i] != 0))
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

int	find_max(t_stack **stack)
{
	t_stack	*current;
	int		max;

	current = *stack;
	max = current->content;
	while (current != NULL)
	{
		if (current->content > max)
			max = current->content;
		current = current->next;
	}
	return (max);
}
