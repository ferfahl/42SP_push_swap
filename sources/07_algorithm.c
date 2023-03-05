/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 22:30:50 by feralves          #+#    #+#             */
/*   Updated: 2023/03/05 14:08:08 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
*@brief counts how many numbers are lower than the first number in the stack and
*returns the percentage of lower numbers
*@param stack the stack to be checked
*@return the percentage of lower numbers
*/
int	ft_calculate_lower(t_stack *stack, int size)
{
	t_node	*temp;
	int		count;
	int		start;
	int		result;

	temp = stack->first;
	count = 0;
	start = temp->data;
	while (temp)
	{
		if (!temp->next)
			break ;
		temp = temp->next;
		if (start > temp->data)
			count++;
	}
	result = (100 * count) / size;
	return (result);
}

/**
*@brief is called to organize the stack when it contains more than 100 elements
*@param s_a the stack A
*@param s_b the stack B
*@param p_b percentage b
*@return none
*/
void	ft_size_100(t_stack *s_a, t_stack *s_b, int p_b)
{
	int	p_a;

	while (s_a->size >= 100)
	{
		p_a = ft_calculate_lower(s_a, s_a->size);
		if (s_b->size > 2)
			p_b = ft_calculate_lower(s_b, s_b->size);
		if (p_a <= 7 && p_b < 83)
		{
			ft_rotate(s_b, 'b');
			ft_push(s_a, s_b, 'b');
		}
		else if (p_a <= 7 && p_b >= 83)
			ft_push(s_a, s_b, 'b');
		else if (p_a > 7 && p_b >= 83)
			ft_rotate(s_a, 'a');
		else if (p_a > 7 && p_b < 83)
			ft_double_rotate(s_a, s_b);
	}
}

/**
*@brief is called when the stack to be sorted has a size between 50 and 99
elements
*@param s_a the stack A
*@param s_b the stack B
*@param p_b percentage b
*@return none
*/
void	ft_size_50(t_stack *s_a, t_stack *s_b, int p_b)
{
	int	p_a;

	while (s_a->size >= 50 && s_a->size < 100)
	{
		p_a = ft_calculate_lower(s_a, s_a->size);
		if (s_b->size > 2)
			p_b = ft_calculate_lower(s_b, s_b->size);
		if (p_a <= 13 && p_b < 71)
		{
			if (s_b->size >= 3 && s_b->first->data > s_b->first->next->data)
			{
				if (s_b->first->data < s_b->first->next->next->data)
					ft_swap(s_b, 'b');
				else
					ft_rotate(s_b, 'b');
			}
			ft_push(s_a, s_b, 'b');
		}
		else if (p_a <= 13 && p_b >= 71)
			ft_push(s_a, s_b, 'b');
		else if (p_a > 13 && p_b >= 71)
			ft_rotate(s_a, 'a');
		else if (p_a > 13 && p_b < 71)
			ft_double_rotate(s_a, s_b);
	}
}

/**
*@brief is called when the stack to be sorted has a size between 5 and 49
elements
*@param s_a the stack A
*@param s_b the stack B
*@param p_b percentage b
*@return none
*/
void	ft_size_5_49(t_stack *s_a, t_stack *s_b, int p_b)
{
	int	p_a;

	while (s_a->size > 5 && s_a->size < 50)
	{
		p_a = ft_calculate_lower(s_a, s_a->size);
		if (s_b->size > 2)
			p_b = ft_calculate_lower(s_b, s_b->size);
		if (p_a <= 33 && p_b < 50)
		{
			ft_rotate(s_b, 'b');
			ft_push(s_a, s_b, 'b');
		}
		else if (p_a <= 33 && p_b >= 50)
			ft_push(s_a, s_b, 'b');
		else if (p_a > 33 && p_b >= 50)
			ft_rotate(s_a, 'a');
		else if (p_a > 33 && p_b < 50)
			ft_double_rotate(s_a, s_b);
	}
}

/**
*@brief The algorithm that checks if 1/3 of A is lower or not, if it is, push it
*to B, else rotate A. Verify if B is part of the 2/3 higher numbers, if it is,
*nothing will be done, else rotate B. if both are false, double rotate
*@param s_a the stack A
*@param s_b the stack B
*@return none
*/
void	ft_algorithm(t_stack *s_a, t_stack *s_b)
{
	int	percentage_b;

	percentage_b = 100;
	ft_size_100(s_a, s_b, percentage_b);
	ft_size_50(s_a, s_b, percentage_b);
	ft_size_5_49(s_a, s_b, percentage_b);
}
