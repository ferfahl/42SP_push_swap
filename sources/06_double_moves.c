/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_double_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:23:30 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 01:40:10 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// // (ss) swap: trocar os dois primeiros elementos do topo das duas pilhas
// void	ft_double_swap(t_stack *stack_a, t_stack *stack_b)
// {
// 	ft_swap(stack_a);
// 	ft_swap(stack_b);
// 	ft_print("ss");
// }

// (ra, rb, rr) rotate: mover o elemento do topo para o final da pilha
void	ft_double_rotate(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a, 'c');
	ft_rotate(stack_b, 'c');
	ft_putstr_fd("rr\n", 2);
}

// (rra, rrb, rrr) reverse rotate: mover o elemento do final da pilha para o
// topo
void	ft_double_reverse_rotate(t_stack *stack_a, t_stack *stack_b)
{
	ft_reverse_rotate(stack_a, 'c');
	ft_reverse_rotate(stack_b, 'c');
	ft_putstr_fd("rrr\n", 2);
}

void	ft_swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a, 's');
	ft_swap(stack_b, 's');
	ft_putstr_fd("ss\n", 2);
}

void	push(t_stack *source, t_stack *dest, char a_or_b)
{
	t_node	*temp;

	if (!source->first)
		return ;
	temp = source->first->next;
	temp->prev = NULL;
	ft_add_front(dest, source->first);
	source->first = temp;
	source->size -= 1;
	if (a_or_b == 'a')
		ft_putstr_fd("pa\n", 2);
	else if (a_or_b == 'b')
		ft_putstr_fd("pb\n", 2);
}
