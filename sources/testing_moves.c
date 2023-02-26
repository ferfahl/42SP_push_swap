/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:52:04 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 01:51:57 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_moves_like(t_stack *stack)
{
	ft_printf("\t before rotate\n");
	ft_print_stack_simple(stack);
	ft_rotate(stack, 'a');
	ft_printf("\t after rotate\n");
	ft_print_stack_simple(stack);
	ft_reverse_rotate(stack, 'a');
	ft_reverse_rotate(stack, 'a');
	ft_printf("\t 2x after reverse rotate\n");
	ft_print_stack_simple(stack);
}
