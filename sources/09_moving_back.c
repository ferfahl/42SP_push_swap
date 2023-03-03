/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_moving_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:13:45 by mcarecho          #+#    #+#             */
/*   Updated: 2023/03/03 03:02:56 by mcarecho         ###   ########.fr       */
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
		if (stack_b->first->data > p_max.value || stack_b->first->data < p_min.value)
		{
			if ((p_max.pos == stack_a->size) && (p_min.pos == 1))
				ft_pa(stack_a, stack_b);
			else if (p_max.pos < (stack_a->size / 2) + 1)
				ft_rotate(stack_a, 'a');
			else
				ft_reverse_rotate(stack_a, 'a');
		}
		else
		{
			p_max = find_position(stack_a, stack_b->first->data);
			if (p_max.pos == stack_a->size)
				ft_pa(stack_a, stack_b);
			else if (p_max.pos < (stack_a->size / 2) + 1)
				ft_rotate(stack_a, 'a');
			else
				ft_reverse_rotate(stack_a, 'a');
		}
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
}
