/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:07:12 by feralves          #+#    #+#             */
/*   Updated: 2023/02/21 15:16:47 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_new_node(int number)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = number;
	new_node->next = NULL;
	return (new_node);
}

void	ft_add_first(t_stack *stack, t_node *new)
{
	stack->first = new;
	stack->last = new;
}

void	ft_add_back(t_stack *stack, t_node *new)
{
	if (stack->first == NULL)
		ft_add_first(stack, new);
	else if (stack && new)
	{
		stack->last->next = new;
		new->next = NULL;
		new->prev = stack->last;
		stack->last = new;
	}
}

void	ft_add_front(t_stack *stack, t_node *new)
{
	if (stack->first == NULL)
		ft_add_first(stack, new);
	else if (stack && new)
	{
		stack->first->prev = new;
		new->next = stack->first;
		new->prev = NULL;
		stack->first = new;
	}
}

void	ft_remove_front(t_stack *stack)
{
	t_node	*temp;

	if (stack)
	{
		temp = stack->first;
		stack->first = stack->first->next;
		stack->first->prev = NULL;
		free(temp);
	}
}
