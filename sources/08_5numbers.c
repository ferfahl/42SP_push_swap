/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_5numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 08:56:12 by mcarecho          #+#    #+#             */
/*   Updated: 2023/03/01 23:30:28 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_greater_pos(t_stack *stack)
{
	t_node	*temp;
	int		pos_max;
	int		value_max;
	int		i;

	i = -1;
	pos_max = 1;
	value_max = stack->first->data;
	temp = stack->first;
	while (++i < stack->size)
	{
		if (value_max < temp->data)
		{
			pos_max = i + 1;
			value_max = temp->data;
		}
		temp = temp->next;
	}
	return (pos_max);
}

int	find_smaller_pos(t_stack *stack)
{
	t_node	*temp;
	int		pos_min;
	int		value_min;
	int		i;

	i = -1;
	pos_min = 1;
	value_min = stack->first->data;
	temp = stack->first;
	while (++i < stack->size)
	{
		if (value_min > temp->data)
		{
			pos_min = i + 1;
			value_min = temp->data;
		}
		temp = temp->next;
	}
	return (pos_min);
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
	int		p_max;
	int		p_min;

	p_max = find_greater_pos(stack);
	p_min = find_smaller_pos(stack);
	if (p_max == 1 && p_min == 3)
	{
		ft_swap(stack, a_or_b);
		ft_reverse_rotate(stack, a_or_b);
	}
	else if (p_min == 1 && p_max == 2)
	{
		ft_swap(stack, a_or_b);
		ft_rotate(stack, a_or_b);
	}
	else if (p_min == 2 && p_max == 3)
		ft_swap(stack, a_or_b);
	else if (p_max == 1 && p_min == 2)
		ft_rotate(stack, a_or_b);
	else if (p_max == 2 && p_min == 3)
		ft_reverse_rotate(stack, a_or_b);
}

void	algorithm_to_5(t_stack *stack_source, t_stack *stack_dest)
{
	int	p_max;
	int	p_min;

	while (stack_source->size > 3)
	{
		p_max = find_greater_pos(stack_source);
		p_min = find_smaller_pos(stack_source);
		if (p_min == 1 || p_max == 1)
			ft_pb(stack_source, stack_dest);
		else if (p_max == stack_source->size || p_min == stack_source->size)
			ft_reverse_rotate(stack_source, 'a');
		else if (p_max == 2 || p_min == 2)
			ft_swap(stack_source, 'a');
		else
			ft_pb(stack_source, stack_dest);
	}
	algorithm_to_3(stack_source, 'a');
	return_to_a(stack_source, stack_dest);
}
