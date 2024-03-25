/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:52:54 by lglauch           #+#    #+#             */
/*   Updated: 2023/11/04 14:42:17 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lastnode;

	lastnode = NULL;
	if (!lst)
		return (0);
	while (lst != 0)
	{
		lastnode = lst;
		lst = lst->next;
	}
	return (lastnode);
}
