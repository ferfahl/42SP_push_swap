/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:22:43 by feralves          #+#    #+#             */
/*   Updated: 2023/01/29 18:37:12 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//fazer uma função para printar se estão certos inicio->fim e fim->inicio

// (pa, pb) push: mover o elemento do topo de uma pilha para a outra
void	push(t_stack *source, t_stack *dest)
{
	if (!source->top)
		return ;
	ft_add_front(&dest, source->top);
	ft_remove_front(&source);
}

// (sa, sb) swap: trocar os dois primeiros elementos do topo de uma pilha
void	swap(t_stack *stack)
{
	if (!stack->top || !stack->top->next)
		return ;
	ft_swap(&stack->top->value, &stack->top->next->value);
	ft_print_move(NULL);
}

// (ra, rb) rotate: mover o elemento do topo para o final da pilha
void	rotate(t_stack *stack)
{
	t_stack	*temp;

	if (!stack->first || !stack->last)
		return ;
	temp = stack->first;
	stack->first = stack->first->next;
	stack->last->next = temp;
	ft_add_back(&stack, temp);
}

// (rra, rrb) reverse rotate: mover o elemento do final da pilha para o topo
void	ft_reverse_rotate(t_stack *stack)
{
	t_stack	*temp;

	if (!stack->first || !stack->last)
		return ;
	temp = stack->last;
	stack->last = stack->last->prev;
	stack->last->next = NULL;
	ft_add_front(&stack, temp);
}
