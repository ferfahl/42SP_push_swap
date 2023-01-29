/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:22:43 by feralves          #+#    #+#             */
/*   Updated: 2023/01/29 13:59:53 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// fazer as funções de push, swap, rotate e reverse rotate
// (pa, pb) push: mover o elemento do topo de uma pilha para a outra
// (rra, rrb, rrr) reverse rotate: mover o elemento do final da pilha para o topo

// (sa, sb, ss) swap: trocar os dois primeiros elementos do topo de uma pilha
void	swap(t_stack *stack)
{
	if (!stack->top || !stack->top->next)
		return ;
	ft_swap(&stack->top->value, &stack->top->next->value);
}

// (ra, rb, rr) rotate: mover o elemento do topo para o final da pilha
void	rotate(t_stack *stack)
{
	if (!stack->top || !stack->bottom)
		return ;
	
}

//mudam as referencias dos ponteiros da lista linkada
//fazer uma função para printar se estão certos inicio->fim e fim->inicio
