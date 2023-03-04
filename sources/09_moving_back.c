/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_moving_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:13:45 by mcarecho          #+#    #+#             */
/*   Updated: 2023/03/04 14:17:12 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_pos(t_stack *stack_a, t_stack *stack_b)
{
	t_move	p_max;
	t_move	p_min;

	while (stack_b->size != 0)
	{
		p_max = find_greater_pos(stack_a);
		p_min = find_smaller_pos(stack_a);
		if (stack_b->size >= 2 && stack_b->first->data < stack_b->first->next->data)
			ft_swap(stack_b, 'b');
		else if (stack_b->first->data > p_max.value)
		{
			ft_pa(stack_a, stack_b);
			if (stack_b->first->data < stack_b->last->data)
				ft_double_rotate(stack_a, stack_b);
			else
				ft_rotate(stack_a, 'a');
		}
		else if (stack_b->first->data < p_min.value)
		{
			while (stack_a->last->data < stack_a->first->data)
				ft_reverse_rotate(stack_a, 'a');
			ft_pa(stack_a, stack_b);
			if (stack_b->size >= 2 && stack_a->first->data > stack_a->first->next->data && stack_b->first->data < stack_b->first->next->data)
				ft_double_swap(stack_a, stack_b);
			else if (stack_b->size >= 2 && stack_a->first->data < stack_a->first->next->data && stack_b->first->data < stack_b->first->next->data)
				ft_swap(stack_b, 'b');
		}
		else
		{
			// ft_print_stack_simple(stack_a, 'a');
			p_max = find_position(stack_a, stack_b->first->data);
			// ft_printf("p_max.pos: %d, stack_a size: %d\n", p_max.pos, stack_a->size);
			if (p_max.pos == 1)
			{
				ft_pa(stack_a, stack_b);
				if (stack_b->size >= 2 && stack_a->first->data > stack_a->first->next->data && stack_b->first->data < stack_b->first->next->data)
					ft_double_swap(stack_a, stack_b);
				else if (stack_b->size >= 2 && stack_a->first->data < stack_a->first->next->data && stack_b->first->data < stack_b->first->next->data)
					ft_swap(stack_b, 'b');
				else
					ft_swap(stack_a, 'a');
			}
			else if (p_max.pos == stack_a->size)
				ft_pa(stack_a, stack_b);
			else if (p_max.pos < (stack_a->size / 2) + 1)
				ft_rotate(stack_a, 'a');
			else
				ft_reverse_rotate(stack_a, 'a');
		}
		ft_print_stack_simple(stack_a, 'a');
		ft_print_stack_simple(stack_b, 'b');
	}
}

void	returning_all(t_stack *stack_a, t_stack *stack_b)
{
	t_move pos_min;

	find_pos(stack_a, stack_b);
	pos_min = find_smaller_pos(stack_a);
	while (pos_min.pos != 1)
	{
		if (pos_min.pos < (stack_a->size / 2) + 1)
			ft_rotate(stack_a, 'a');
		else
			ft_reverse_rotate(stack_a, 'a');
		pos_min = find_smaller_pos(stack_a);
	}
	ft_printf("Final stack_a\n");
	ft_print_stack_simple(stack_a, 'a');
	ft_print_stack_simple(stack_b, 'b');
}
