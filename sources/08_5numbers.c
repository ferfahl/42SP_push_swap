/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_5numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 08:56:12 by mcarecho          #+#    #+#             */
/*   Updated: 2023/03/04 16:15:10 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move	find_greater_pos(t_stack *stack)
{
	t_node	*temp;
	t_move	move;
	int		i;

	i = 0;
	move.pos = 1;
	move.value = stack->first->data;
	temp = stack->first;
	while (i < stack->size)
	{
		if (move.value < temp->data)
		{
			move.pos = i + 1;
			move.value = temp->data;
		}
		temp = temp->next;
		i++;
	}
	// ft_printf("in a large: %d, %d\n", move.pos, move.value);
	return (move);
}

t_move	find_smaller_pos(t_stack *stack)
{
	t_node	*temp;
	t_move	move;
	int		i;

	i = 0;
	move.pos = 1;
	move.value = stack->first->data;
	temp = stack->first;
	while (i < stack->size)
	{
		if (move.value > temp->data)
		{
			move.pos = i + 1;
			move.value = temp->data;
		}
		temp = temp->next;
		i++;
	}
	// ft_printf("in a small: %d, %d\n", move.pos, move.value);
	return (move);
}

void	return_to_a(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 5 || stack_b->size == 0)
		return ;
	if (stack_b->first->data > stack_a->last->data)
	{
		ft_pa(stack_a, stack_b);
		ft_rotate(stack_a, 'a');
	}
	else if (stack_b->first->data < stack_a->first->data)
		ft_pa(stack_a, stack_b);
	else
	{
		ft_rotate(stack_a, 'a');
	}
	return_to_a(stack_a, stack_b);
}

void	algorithm_to_3(t_stack *stack, char a_or_b)
{
	t_move		p_max;
	t_move		p_min;

	p_max = find_greater_pos(stack);
	p_min = find_smaller_pos(stack);
	if (p_max.pos == 1 && p_min.pos == 3)
	{
		ft_swap(stack, a_or_b);
		ft_reverse_rotate(stack, a_or_b);
	}
	else if (p_min.pos == 1 && p_max.pos == 2)
	{
		ft_swap(stack, a_or_b);
		ft_rotate(stack, a_or_b);
	}
	else if (p_min.pos == 2 && p_max.pos == 3)
		ft_swap(stack, a_or_b);
	else if (p_max.pos == 1 && p_min.pos == 2)
		ft_rotate(stack, a_or_b);
	else if (p_max.pos == 2 && p_min.pos == 3)
		ft_reverse_rotate(stack, a_or_b);
}

void	algorithm_to_5(t_stack *stack_source, t_stack *stack_dest)
{
	t_move	p_max;
	t_move	p_min;

	while (stack_source->size > 3)
	{
		p_max = find_greater_pos(stack_source);
		p_min = find_smaller_pos(stack_source);
		if (p_min.pos == 1 || p_max.pos == 1)
			ft_pb(stack_source, stack_dest);
		else if (p_max.pos == stack_source->size || p_min.pos == stack_source->size)
			ft_reverse_rotate(stack_source, 'a');
		else if (p_max.pos == 2 || p_min.pos == 2)
			ft_swap(stack_source, 'a');
		else if (p_min.pos == 4 || p_max.pos == 4)
			ft_reverse_rotate(stack_source, 'a');
		else
			ft_pb(stack_source, stack_dest);
	}
	algorithm_to_3(stack_source, 'a');
	return_to_a(stack_source, stack_dest);
	// ft_printf("final sort 5\n");
	// ft_print_stack_simple(stack_source, 'a');
}
