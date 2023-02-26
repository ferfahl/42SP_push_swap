/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:52:04 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 02:57:23 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_test_swap(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("===============Testing swap (sa or sb)===============\n");
	ft_print_stack_simple(stack_a, 'a');
	ft_print_stack_simple(stack_b, 'b');
	ft_printf("======================== SWAP ========================\n");
	ft_swap(stack_a, 'a');
	ft_print_stack_simple(stack_a, 'a');
	ft_print_stack_simple(stack_b, 'b');
	ft_printf("==================== DOUBLE SWAP =====================\n");
	ft_double_swap(stack_a, stack_b);
	ft_print_stack_simple(stack_a, 'a');
	ft_print_stack_simple(stack_b, 'b');
}

void	ft_test_push(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("================Testing push(pa or pb)================\n");
	ft_print_stack_simple(stack_a, 'a');
	ft_print_stack_simple(stack_b, 'b');
	ft_printf("========================= PB =========================\n");
	ft_pb(stack_a, stack_b);
	ft_print_stack_simple(stack_a, 'a');
	ft_print_stack_simple(stack_b, 'b');
	ft_printf("======================= 2x PB ========================\n");
	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	ft_print_stack_simple(stack_a, 'a');
	ft_print_stack_simple(stack_b, 'b');
	ft_printf("========================= PA =========================\n");
	ft_pa(stack_a, stack_b);
	ft_print_stack_simple(stack_a, 'a');
	ft_print_stack_simple(stack_b, 'b');
}

void	ft_test_rotate(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("==============Testing rotate(ra, rb, rr)==============\n");
	ft_print_stack_simple(stack_a, 'a');
	ft_print_stack_simple(stack_b, 'b');
	ft_printf("========================= RA =========================\n");
	ft_rotate(stack_a, 'a');
	ft_print_stack_simple(stack_a, 'a');
	ft_print_stack_simple(stack_b, 'b');
	ft_printf("========================= RR =========================\n");
	ft_double_rotate(stack_a, stack_b);
	ft_print_stack_simple(stack_a, 'a');
	ft_print_stack_simple(stack_b, 'b');
}

void	ft_test_reverse_rotate(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("========Testing reverse rotate(rra, rrb, rrr)=========\n");
	ft_print_stack_simple(stack_a, 'a');
	ft_print_stack_simple(stack_b, 'b');
	ft_printf("======================== RRA =========================\n");
	ft_reverse_rotate(stack_a, 'a');
	ft_print_stack_simple(stack_a, 'a');
	ft_print_stack_simple(stack_b, 'b');
	ft_printf("======================== RRR =========================\n");
	ft_double_reverse_rotate(stack_a, stack_b);
	ft_print_stack_simple(stack_a, 'a');
	ft_print_stack_simple(stack_b, 'b');
}

void	ft_moves_like(t_stack *stack_a, t_stack *stack_b)
{
	ft_test_push(stack_a, stack_b);
	ft_test_swap(stack_a, stack_b);
	ft_test_rotate(stack_a, stack_b);
	ft_test_reverse_rotate(stack_a, stack_b);
}
