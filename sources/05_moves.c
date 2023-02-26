/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:18:35 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 01:52:59 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// (pa, pb) push: mover o elemento do topo de uma pilha para a outra

//	ft_remove_front(&source);

void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	ft_push(stack_b, stack_a, 'a');
}

void	ft_pb(t_stack *stack_a, t_stack *stack_b)
{
	ft_push(stack_a, stack_b, 'b');
}

// (sa, sb) swap: trocar os dois primeiros elementos do topo de uma pilha

void	ft_swap(t_stack *stack, char a_or_b)
{
	t_node	*temp;

	if (!stack->first || !stack->first->next)
		return ;
	temp = stack->first;
	stack->first = stack->first->next;
	temp->next = stack->first->next;
	temp->prev = stack->first;
	stack->first->next = temp;
	stack->first->prev = NULL;
	temp->next->prev = temp;
	if (a_or_b == 'a')
		ft_putstr_fd("sa\n", 2);
	else if (a_or_b == 'b')
		ft_putstr_fd("sb\n", 2);
}
	// ft_swap(&stack->first->data, &stack->first->next->data);
//	ft_print_move(NULL);

// (ra, rb) rotate: mover o elemento do topo para o final da pilha
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

// (rra, rrb) reverse rotate: mover o elemento do final da pilha para o topo
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
