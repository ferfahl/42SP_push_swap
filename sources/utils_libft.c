/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:07:12 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 20:42:14 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
*@brief creates a new node
*@param number the number to be stored in the node
*@return the new node
*/
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

/**
*@brief adds a new node to the stack (that's empty)
*@param stack the stack to be added the new node
*@param new the new node to be added
*@return none
*/
void	ft_add_first(t_stack *stack, t_node *new)
{
	stack->first = new;
	stack->last = new;
	stack->size += 1;
	new->next = NULL;
}

/**
*@brief adds a new node to the end of the stack
*@param stack the stack to be added the new node
*@param new the new node to be added
*@return none
*/
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
		stack->size += 1;
	}
}

/**
*@brief adds a new node to the beginning of the stack
*@param stack the stack to be added the new node
*@param new the new node to be added
*@return none
*/
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
		stack->size += 1;
	}
}

/**
*@brief removes the first node of the stack
*@param stack the stack to be removed the first node
*@return none
*/
void	ft_remove_front(t_stack *stack)
{
	t_node	*temp;

	if (stack)
	{
		temp = stack->first;
		stack->first = stack->first->next;
		stack->first->prev = NULL;
		stack->size -= 1;
		free(temp);
	}
}
