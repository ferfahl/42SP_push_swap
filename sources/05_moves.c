/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:18:35 by feralves          #+#    #+#             */
/*   Updated: 2023/03/05 14:16:20 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
*@brief push the first element of the stack to the other stack
*@param source the stack to be pushed
*@param dest the stack to receive the element
*@param a_or_b the name of the stack to be pushed
*@return none
*/
void	ft_push(t_stack *source, t_stack *dest, char a_or_b)
{
	t_node	*temp;

	temp = NULL;
	if (!source->first)
		return ;
	if (source->first->next != NULL)
	{
		temp = source->first->next;
		temp->prev = NULL;
	}
	ft_add_front(dest, source->first);
	source->first = temp;
	source->size -= 1;
	if (a_or_b == 'a')
		ft_putstr_fd("pa\n", 1);
	else if (a_or_b == 'b')
		ft_putstr_fd("pb\n", 1);
}

/**
*@brief swaps the first two elements of the stack
*@param stack the stack to be swapped
*@param a_or_b the name of the stack to be swapped
*@return none
*/
void	ft_swap(t_stack *stack, char a_or_b)
{
	t_node	*temp1;
	t_node	*temp2;

	if (!stack->first || !stack->last || stack->size == 1)
		return ;
	temp1 = stack->first;
	temp2 = stack->first->next;
	if (!temp2)
		return ;
	temp1->next = temp2->next;
	temp1->prev = temp2;
	temp2->prev = NULL;
	temp2->next = temp1;
	if (temp1->next)
		temp1->next->prev = temp1;
	stack->first = temp2;
	if (a_or_b == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (a_or_b == 'b')
		ft_putstr_fd("sb\n", 1);
}

/**
*@brief rotate: moves the top element to the end of the stack
*@param stack the stack to be rotated
*@param a_or_b the name of the stack to be rotated
*@return none
*/
void	ft_rotate(t_stack *stack, char a_or_b)
{
	t_node	*temp;

	if (!stack->first || !stack->last || stack->size == 1)
		return ;
	temp = stack->first;
	stack->first = stack->first->next;
	stack->last->next = temp;
	stack->size--;
	ft_add_back(stack, temp);
	if (a_or_b == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (a_or_b == 'b')
		ft_putstr_fd("rb\n", 1);
}

/**
*@brief reverse rotate: moves the last element to the top of the stack
*@param stack the stack to be rotated
*@param a_or_b the name of the stack to be rotated
*@return none
*/
void	ft_reverse_rotate(t_stack *stack, char a_or_b)
{
	t_node	*temp;

	if (!stack->first || !stack->last || stack->size == 1)
		return ;
	temp = stack->last;
	stack->last = stack->last->prev;
	stack->last->next = NULL;
	stack->size--;
	ft_add_front(stack, temp);
	if (a_or_b == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (a_or_b == 'b')
		ft_putstr_fd("rrb\n", 1);
}

/**
*@brief calls functions to sort the stack
*@param stack_a the stack to be sorted
*@param stack_b the stack to help sorting
*@return none
*/
void	ft_moves_like(t_stack *stack_a, t_stack *stack_b)
{
	ft_algorithm(stack_a, stack_b);
	algorithm_to_5(stack_a, stack_b);
	returning_all(stack_a, stack_b);
}
