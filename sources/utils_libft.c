/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:07:12 by feralves          #+#    #+#             */
/*   Updated: 2023/01/29 18:46:05 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_new_node(void *number)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = number;
	new_node->next = NULL;
	return (new_node);
}

void	ft_add_back(t_stack **stack, t_node *new)
{
	if (stack && new)
	{
		stack->last->next = new;
		new->next = NULL;
		new->prev = stack->last;
		stack->last = new;
	}
}

void	ft_add_front(t_stack **stack, t_node *new)
{
	if (stack && new)
	{
		stack->first->prev = new;
		new->next = stack->first;
		new->prev = NULL;
		stack->first = new;
	}
}

void	ft_remove_front(t_stack *stack)
{
	t_node *temp;

	if (stack)
	{
		temp = stack->first;
		stack->first = stack->first->next;
		stack->first->prev = NULL;
		free(temp);
	}
}
