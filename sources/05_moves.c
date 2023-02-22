/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:18:35 by feralves          #+#    #+#             */
/*   Updated: 2023/02/22 16:16:17 by mcarecho         ###   ########.fr       */
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
//	ft_print_move(NULL);

// (ra, rb) rotate: mover o elemento do topo para o final da pilha
void	ft_rotate(t_stack *stack)
{
	t_node	*temp;

	if (!stack->first || !stack->last)
		return ;
	temp = stack->first;
	stack->first = stack->first->next;
	stack->last->next = temp;
	ft_add_back(stack, temp);
}

// (rra, rrb) reverse rotate: mover o elemento do final da pilha para o topo
void	ft_reverse_rotate(t_stack *stack)
{
	t_node	*temp;

	if (!stack->first || !stack->last)
		return ;
	temp = stack->last;
	stack->last = stack->last->prev;
	stack->last->next = NULL;
	ft_add_front(stack, temp);
}
