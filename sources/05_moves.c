/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:18:35 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 01:46:11 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// (pa, pb) push: mover o elemento do topo de uma pilha para a outra
void	push(t_stack *source, t_stack *dest)
{
	if (!source->first)
		return ;
	ft_add_front(dest, source->first);
}
//	ft_remove_front(&source);

// (sa, sb) swap: trocar os dois primeiros elementos do topo de uma pilha
	// if (!stack->first || !stack->first->next)
	// 	return ;
void	swap(t_stack *stack)
{
	(void)stack;
}
	// ft_swap(&stack->first->data, &stack->first->next->data);

/**
*@brief rotate: moves the top element to the end of the stack
*@param stack the stack to be rotated
*@param a_or_b the name of the stack to be rotated
*@return none
*/
void	ft_rotate(t_stack *stack, char a_or_b)
{
	t_node	*temp;

	if (!stack->first || !stack->last)
		return ;
	temp = stack->first;
	stack->first = stack->first->next;
	stack->last->next = temp;
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

	if (!stack->first || !stack->last)
		return ;
	temp = stack->last;
	stack->last = stack->last->prev;
	stack->last->next = NULL;
	ft_add_front(stack, temp);
	if (a_or_b == 'a')
		ft_putstr_fd("rra\n", 2);
	else if (a_or_b == 'b')
		ft_putstr_fd("rrb\n", 2);
}
