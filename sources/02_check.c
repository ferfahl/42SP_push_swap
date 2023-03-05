/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:02:49 by feralves          #+#    #+#             */
/*   Updated: 2023/03/03 01:59:19 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
*@brief checks if the arguments are numbers
*@param argv the arguments
*@return 1 if true, exits if false
*/
int	check_int(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (!(ft_isdigit(argv[i][j])))
			error_simple();
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				error_simple();
			j++;
		}
		i++;
	}
	return (1);
}

/**
*@brief checks if the list is sorted
*@param list the list to be checked
*@return TRUE or FALSE
*/
t_bool	check_sorted(t_data *list)
{
	t_data	*temp;

	temp = list;
	while (temp->next != NULL)
	{
		if (temp->index > temp->next->index)
			return (FALSE);
		if (!temp->next)
			break ;
		temp = temp->next;
	}
	return (TRUE);
}

/**
*@brief check if stack is sorted
*@param stack the stack to be checked
*@return TRUE or FALSE
*/
t_move	find_position(t_stack *stack, int value)
{
	t_node	*temp;
	t_move	move;

	temp = stack->first;
	move.pos = 1;
	while (temp)
	{
		if (!temp->next)
			break ;
		if ((temp->next->data > value) && (temp->data < value))
			return (move);
		temp = temp->next;
		move.pos++;
	}
	return (move);
}
