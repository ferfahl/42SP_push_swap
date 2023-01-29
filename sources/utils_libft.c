/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:07:12 by feralves          #+#    #+#             */
/*   Updated: 2023/01/29 14:08:18 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}


void	ft_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (*lst == NULL)
		(*lst) = new;
	else
	{
		last = ft_stack_last(*lst);
		last->next = new;
	}
}

void	ft_add_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}
