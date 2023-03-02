/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:18:35 by feralves          #+#    #+#             */
/*   Updated: 2023/03/01 23:23:43 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// (pa, pb) push: mover o elemento do topo de uma pilha para a outra
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
		ft_putstr_fd("pa\n", 2);
	else if (a_or_b == 'b')
		ft_putstr_fd("pb\n", 2);
}

/**
*@brief swaps the first two elements of the stack
*@param stack the stack to be swapped
*@param a_or_b the name of the stack to be swapped
*@return none
*/
void	ft_swap(t_stack *stack, char a_or_b)
{
	t_node	*temp;
	t_node	*aux;

	if (!stack->first || !stack->last || stack->size == 1)
		return ;
	temp = stack->first;
	aux = stack->first->next;
	if (!aux)
		return ;
	temp->next = aux->next;
	temp->prev = aux;
	aux->prev = NULL;
	aux->next = temp;
	stack->first = aux;
	temp->next->prev = temp;
	if (a_or_b == 'a')
		ft_putstr_fd("sa\n", 2);
	else if (a_or_b == 'b')
		ft_putstr_fd("sb\n", 2);
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
		ft_putstr_fd("ra\n", 2);
	else if (a_or_b == 'b')
		ft_putstr_fd("rb\n", 2);
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
		ft_putstr_fd("rra\n", 2);
	else if (a_or_b == 'b')
		ft_putstr_fd("rrb\n", 2);
}
