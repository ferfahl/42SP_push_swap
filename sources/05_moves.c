/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:22:43 by feralves          #+#    #+#             */
/*   Updated: 2023/01/28 21:31:44 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// fazer as funções de push, swap, rotate e reverse rotate
// (pa, pb) push: mover o elemento do topo de uma pilha para a outra
// (sa, sb, ss) swap: trocar os dois primeiros elementos do topo de uma pilha
// (ra, rb, rr) rotate: mover o elemento do topo para o final da pilha
// (rra, rrb, rrr) reverse rotate: mover o elemento do final da pilha para o topo

void	swap(t_stack *stack)
{
	t_node *tmp;

	if (stack->size > 1)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		tmp->next = stack->top->next;
		stack->top->next = tmp;
	}
}


//mudam as referencias dos ponteiros da lista linkada
//fazer uma função para printar se estão certos inicio->fim e fim->inicio
