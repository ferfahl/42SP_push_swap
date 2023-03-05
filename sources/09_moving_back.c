/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_moving_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:13:45 by mcarecho          #+#    #+#             */
/*   Updated: 2023/03/05 02:32:54 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
*@brief handles the case where the top value of the stack_b is greater than any value on the stack_a. It moves the value from the stack_b to the stack_a and does a double rotation on the stack_a if the moved value is at the end of the stack_a.
*@param s_a the stack A
*@param s_b the stack B
*@return none
*/

void	s_bigger_value(t_stack *s_a, t_stack *s_b)
{
	ft_pa(s_a, s_b);
	if (s_b->first->data < s_b->last->data)
		ft_double_rotate(s_a, s_b);
	else
		ft_rotate(s_a, 'a');
}

/**
*@brief handles the case where the top value of the stack_b is less than any value on the stack_a. It moves the value from the stack_b to the stack_a and does one or more reverse rotations on the stack_a if the moved value is at the top of the stack_a
*@param s_a the stack A
*@param s_b the stack B
*@return none
*/

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

/**
*@brief handles all other cases where the top value from the stack_b needs to be pushed into the stack_a at a different position
*@param s_a the stack A
*@param s_b the stack B
*@return none
*/

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

/**
*@brief is responsible for finding the correct position of elements in stack B relative to stack A.
*@param s_a the stack A
*@param s_b the stack B
*@return none
*/

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

/**
*@brief sort the stack_a. First, the function calls the find_pos function to position each element of the stack_b relative to the stack_a stack. The function then finds the position of the smallest element in the stack_a via the find_smaller_pos function. Then, the function rotates the stack_a elements until the smallest element is in the first position of the stack. With this, the stack_a will be completely sorted.
*@param s_a the stack A
*@param s_b the stack B
*@return none
*/

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
