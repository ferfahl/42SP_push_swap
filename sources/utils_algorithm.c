/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 22:32:05 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 01:18:04 by feralves         ###   ########.fr       */
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
	t_stack	*temp;
	int		count;
	int		start;
	int		result;

	temp = stack;
	count = 0;
	start = temp->data;
	while (temp)
	{
		if (stack < temp->next->data)
			count++;
		temp = temp->next;
	}
	result = (100 * count) / size;
	return (result);
}
