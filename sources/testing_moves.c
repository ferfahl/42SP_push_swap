/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:52:04 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 01:42:30 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_test_swap(t_stack *stack)
{
	ft_printf("===============Testing swap (sa or sb)===============\n");
	ft_print_stack_simple(stack, ' ');
	ft_printf("======================== SWAP ========================\n");
	ft_swap(stack, ' ');
	ft_print_stack_simple(stack, ' ');
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
	ft_printf("========================= PB =========================\n");
	ft_pb(stack_a, stack_b);
	ft_print_stack_simple(stack_a, 'a');
	ft_print_stack_simple(stack_b, 'b');
	ft_printf("========================= PA =========================\n");
	ft_pa(stack_a, stack_b);
	ft_print_stack_simple(stack_a, 'a');
	ft_print_stack_simple(stack_b, 'b');
}

void	ft_test_rotate(t_stack *stack)
{
	ft_printf("===============Testing rotate(ra or rb)===============\n");
	ft_print_stack_simple(stack, ' ');
	ft_printf("======================= ROTATE =======================\n");
	ft_rotate(stack, ' ');
	ft_print_stack_simple(stack, ' ');
}

void	ft_test_reverse_rotate(t_stack *stack)
{
	ft_printf("==========Testing reverse rotate(rra or rrb)==========\n");
	ft_print_stack_simple(stack, ' ');
	ft_printf("====================REVERSE ROTATE====================\n");
	ft_reverse_rotate(stack, ' ');
	ft_print_stack_simple(stack, ' ');
}

void	ft_moves_like(t_stack *stack_a, t_stack *stack_b)
{
	ft_test_swap(stack_a);
	ft_test_push(stack_a, stack_b);
	ft_test_rotate(stack_a);
	ft_test_reverse_rotate(stack_a);
}
