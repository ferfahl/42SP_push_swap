/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_5numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 08:56:12 by mcarecho          #+#    #+#             */
/*   Updated: 2023/03/05 02:35:59 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
*@brief the function returns the structure moves with the position and value of
the largest element on the stack.
*@param stack stack to find the largest element
*@return largest element on the stack
*/

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
	return (move);
}

/**
*@brief the function returns the structure moves with the position and value of
the smallest element on the stack.
*@param stack stack to find the smallest element
*@return smallest element on the stack
*/

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
	return (move);
}

/**
*@brief This function is responsible for moving all elements from stack B to
stack A
*@param stack_a the stack A
*@param stack_b the stack B
*@return none
*/

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

/**
*@brief This function implements an algorithm to sort a stack with a maximum of
3 elements. The function is called recursively until the stack is sorted.
*@param stack the stack
*@param a_or_b indicating whether it is A or B for the movement
*@return none
*/

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

/**
*@brief This function implements the algorithm for sorting a stack of size 5.
The strategy is to split the stack in two: the first stack with the 3 smallest
elements and the second stack with the 2 largest elements.
*@param s_source the source stack, usually stack a
*@param s_dest the dest stack, usually stack b
*@return none
*/

void	algorithm_to_5(t_stack *s_source, t_stack *s_dest)
{
	t_move	p_max;
	t_move	p_min;

	while (s_source->size > 3)
	{
		p_max = find_greater_pos(s_source);
		p_min = find_smaller_pos(s_source);
		if (p_min.pos == 1 || p_max.pos == 1)
			ft_pb(s_source, s_dest);
		else if (p_max.pos == s_source->size || p_min.pos == s_source->size)
			ft_reverse_rotate(s_source, 'a');
		else if (p_max.pos == 2 || p_min.pos == 2)
			ft_swap(s_source, 'a');
		else if (p_min.pos == 4 || p_max.pos == 4)
			ft_reverse_rotate(s_source, 'a');
		else
			ft_pb(s_source, s_dest);
	}
	algorithm_to_3(s_source, 'a');
	return_to_a(s_source, s_dest);
}
