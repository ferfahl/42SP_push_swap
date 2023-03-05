/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_moving_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:13:45 by mcarecho          #+#    #+#             */
/*   Updated: 2023/03/05 01:48:08 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_bigger_value(t_stack *s_a, t_stack *s_b)
{
	ft_pa(s_a, s_b);
	if (s_b->first->data < s_b->last->data)
		ft_double_rotate(s_a, s_b);
	else
		ft_rotate(s_a, 'a');
}

void	s_smaler_value(t_stack *s_a, t_stack *s_b)
{
	while (s_a->last->data < s_a->first->data)
		ft_reverse_rotate(s_a, 'a');
	ft_pa(s_a, s_b);
	if (s_b->size >= 2 && s_a->first->data > s_a->first->next->data
		&& s_b->first->data < s_b->first->next->data)
		ft_double_swap(s_a, s_b);
	else if (s_b->size >= 2 && s_a->first->data < s_a->first->next->data
		&& s_b->first->data < s_b->first->next->data)
		ft_swap(s_b, 'b');
}

void	s_else(t_stack *s_a, t_stack *s_b, t_move	p_max)
{
	p_max = find_position(s_a, s_b->first->data);
	if (p_max.pos == 1)
	{
		ft_pa(s_a, s_b);
		if (s_b->size >= 2 && s_a->first->data > s_a->first->next->data
			&& s_b->first->data < s_b->first->next->data)
			ft_double_swap(s_a, s_b);
		else if (s_b->size >= 2 && s_a->first->data < s_a->first->next->data
			&& s_b->first->data < s_b->first->next->data)
			ft_swap(s_b, 'b');
		else
			ft_swap(s_a, 'a');
	}
	else if (p_max.pos == s_a->size)
		ft_pa(s_a, s_b);
	else if (p_max.pos < (s_a->size / 2) + 1)
		ft_rotate(s_a, 'a');
	else
		ft_reverse_rotate(s_a, 'a');
}

void	find_pos(t_stack *s_a, t_stack *s_b)
{
	t_move	p_max;
	t_move	p_min;

	while (s_b->size != 0)
	{
		p_max = find_greater_pos(s_a);
		p_min = find_smaller_pos(s_a);
		if (s_b->size >= 2 && s_b->first->data < s_b->first->next->data)
			ft_swap(s_b, 'b');
		else if (s_b->first->data > p_max.value)
			s_bigger_value(s_a, s_b);
		else if (s_b->first->data < p_min.value)
			s_smaler_value(s_a, s_b);
		else
			s_else(s_a, s_b, p_max);
	}
}

void	returning_all(t_stack *stack_a, t_stack *stack_b)
{
	t_move	pos_min;

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
