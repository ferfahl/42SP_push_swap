/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_5numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 08:56:12 by mcarecho          #+#    #+#             */
/*   Updated: 2023/03/04 14:45:30 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_move	find_greater_pos(t_stack *stack)
// {
// 	t_node	*temp;
// 	t_move	move;
// 	int		i;

// 	i = 0;
// 	move.pos = 1;
// 	move.value = stack->first->first->data;
// 	temp = stack->first;
// 	while (i < stack->size)
// 	{
// 		if (move.value < temp->data)
// 		{
// 			move.pos = i + 1;
// 			move.value = temp->data;
// 		}
// 		temp = temp->next;
// 		i++;
// 	}
// 	// ft_printf("in a large: %d, %d\n", move.pos, move.value);
// 	return (move);
// }

// t_move	find_smaller_pos(t_stack *stack)
// {
// 	t_node	*temp;
// 	t_move	move;
// 	int		i;

// 	i = 0;
// 	move.pos = 1;
// 	move.value = stack->first->first->data;
// 	temp = stack->first;
// 	while (i < stack->size)
// 	{
// 		if (move.value > temp->data)
// 		{
// 			move.pos = i + 1;
// 			move.value = temp->data;
// 		}
// 		temp = temp->next;
// 		i++;
// 	}
// 	// ft_printf("in a small: %d, %d\n", move.pos, move.value);
// 	return (move);
// }

// void	return_to_a(t_stack *stack_a, t_stack *stack_b)
// {
// 	if (stack_a->size == 5 || stack_b->size == 0)
// 		return ;
// 	if (stack_b->first->first->data > stack_a->last->first->data)
// 	{
// 		ft_pa(stack_a, stack_b);
// 		ft_rotate(stack_a, 'a');
// 	}
// 	else if (stack_b->first->first->data < stack_a->first->first->data)
// 		ft_pa(stack_a, stack_b);
// 	else
// 	{
// 		ft_rotate(stack_a, 'a');
// 	}
// 	return_to_a(stack_a, stack_b);
// }

// void	algorithm_to_3(t_stack *stack, char a_or_b)
// {
// 	t_move		p_max;
// 	t_move		p_min;

// 	p_max = find_greater_pos(stack);
// 	p_min = find_smaller_pos(stack);
// 	if (p_max.pos == 1 && p_min.pos == 3)
// 	{
// 		ft_swap(stack, a_or_b);
// 		ft_reverse_rotate(stack, a_or_b);
// 	}
// 	else if (p_min.pos == 1 && p_max.pos == 2)
// 	{
// 		ft_swap(stack, a_or_b);
// 		ft_rotate(stack, a_or_b);
// 	}
// 	else if (p_min.pos == 2 && p_max.pos == 3)
// 		ft_swap(stack, a_or_b);
// 	else if (p_max.pos == 1 && p_min.pos == 2)
// 		ft_rotate(stack, a_or_b);
// 	else if (p_max.pos == 2 && p_min.pos == 3)
// 		ft_reverse_rotate(stack, a_or_b);
// }

// void	algorithm_to_5(t_stack *stack_source, t_stack *stack_dest)
// {
// 	t_move	p_max;
// 	t_move	p_min;

// 	while (stack_source->size > 3)
// 	{
// 		p_max = find_greater_pos(stack_source);
// 		p_min = find_smaller_pos(stack_source);
// 		if (p_min.pos == 1 || p_max.pos == 1)
// 			ft_pb(stack_source, stack_dest);
// 		else if (p_max.pos == stack_source->size || p_min.pos == stack_source->size)
// 			ft_reverse_rotate(stack_source, 'a');
// 		else if (p_max.pos == 2 || p_min.pos == 2)
// 			ft_swap(stack_source, 'a');
// 		else
// 			ft_pb(stack_source, stack_dest);
// 	}
// 	algorithm_to_3(stack_source, 'a');
// 	return_to_a(stack_source, stack_dest);
// 	ft_printf("final sort 5\n");
// 	ft_print_stack_simple(stack_source, 'a');
// }

int	stack_is_sorted(t_stack *stack)
{
	while (stack->first->next)
	{
		if (stack->first->data > stack->first->next->data)
			return (FALSE);
		stack->first = stack->first->next;
	}
	return (TRUE);
}


void	sort_2(t_stack *st)
{
	if (st->first->data > st->first->next->data)
		ft_swap(st, 'a');
}

void	sort_3(t_stack *st)
{
	if (stack_is_sorted(st))
		return ;
	if (st->first->data > st->first->next->data && st->first->data < st->first->next->next->data)
	{
		ft_swap(st, 'a');
		return ;
	}
	if (st->first->data < st->first->next->data && st->first->data > st->first->next->next->data)
	{
		ft_reverse_rotate(st, 'a');
		return ;
	}
	if (st->first->data < st->first->next->data && st->first->data < st->first->next->next->data)
	{
		ft_reverse_rotate(st, 'a');
		sort_3(st);
		return ;
	}
	if (st->first->data > st->first->next->data && st->first->next->data > st->first->next->next->data)
	{
		ft_swap(st, 'a');
		sort_3(st);
	}
	else if (st->first->data > st->first->next->data && st->first->data > st->first->next->next->data)
		ft_rotate(st, 'a');
}

void	sort_4(t_stack **a, t_stack **b, t_stack *st, int data)
{
	if (stack_is_sorted(st))
		return ;
	if (data == 0 || data == 3)
	{
		ft_pb(*a, *b);
		sort_3(st);
		ft_pa(*a, *b);
		if (data == 3)
			ft_rotate(st, 'a');
	}
	else if (data == 1)
	{
		ft_pb(*a, *b);
		sort_3(st);
		ft_pa(*a, *b);
		ft_swap(st, 'a');
	}
	else if (data == 2)
	{
		ft_swap(st, 'a');
		sort_4(a, b, *a, st->first->data);
	}
}

void	sort_5(t_stack **a, t_stack **b, t_stack *st)
{
	if (stack_is_sorted(st))
		return ;
	if (st->first->next->next->next->data == 4)
		ft_reverse_rotate(st, 'a');
	if (st->first->next->next->next->next->data == 4)
		ft_reverse_rotate(st, 'a');
	if (st->first->next->next->data == 4)
		ft_rotate(st, 'a');
	if (st->first->next->data == 4)
		ft_rotate(st, 'a');
	if (st->first->data == 4)
	{
		ft_pb(*a, *b);
		sort_4(a, b, st, st->first->data);
		ft_pa(*a, *b);
		ft_rotate(st, 'a');
	}
}

void	algorithm_to_5(t_stack *stack_source, t_stack *stack_dest)
{
	int		max;

	max = stack_source->size - 1;
	if (max == 1)
		sort_2(stack_source);
	if (max == 2)
		sort_3(stack_source);
	if (max == 3)
		sort_4(&stack_source, &stack_dest, stack_source, stack_source->first->data);
	if (max == 4)
		sort_5(&stack_source, &stack_dest, stack_source);
}