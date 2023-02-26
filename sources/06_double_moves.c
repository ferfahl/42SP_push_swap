/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_double_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:23:30 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 01:48:01 by feralves         ###   ########.fr       */
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

/**
*@brief doube rotate moves the top element to the end of the stack on both 
*stacks
*@param stack_a the first stack to be rotated
*@param stack_b the second stack to be rotated
*@return none
*/
void	ft_double_rotate(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a, 'c');
	ft_rotate(stack_b, 'c');
	ft_putstr_fd("rr\n", 2);
}

/**
*@brief souble reverse rotate moves the last element to the top of the stack on
*both stacks
*@param stack_a the first stack to be rotated
*@param stack_b the second stack to be rotated
*@return none
*/
void	ft_double_reverse_rotate(t_stack *stack_a, t_stack *stack_b)
{
	ft_reverse_rotate(stack_a, 'c');
	ft_reverse_rotate(stack_b, 'c');
	ft_putstr_fd("rrr\n", 2);
}
