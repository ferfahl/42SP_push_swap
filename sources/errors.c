/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:42:17 by feralves          #+#    #+#             */
/*   Updated: 2023/03/03 02:17:53 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
*@brief frees the stack
*@param stack the stack to be freed
*@return none
*/
void	ft_free_stack(t_stack *stack)
{
	if (stack == NULL)
		return ;
	ft_clear_node(stack->first);
	stack->first = NULL;
	stack->last = NULL;
	free(stack);
	stack = NULL;
}

/**
*@brief frees the list
*@param list the list to be freed
*@return none
*/
void	ft_free_list(t_data **list)
{
	t_data	*aux;

	while (*list)
	{
		aux = *list;
		(*list) = (*list)->next;
		free (aux);
	}
	free (list);
}

/**
*@brief if error, prints the error message and frees the stack or list
*@param data the stack or list to be freed
*@param a the type of data to be freed
*@return none
*/
void	if_error(void *data, char a)
{
	ft_putstr_fd("Error\n", 1);
	if (a == 'l')
		ft_free_list(data);
	else if (a == 's')
		ft_free_stack(data);
	exit (1);
}

/**
*@brief if error and no data to be freed, prints the error message
*@param void
*@return none
*/
void	error_simple(void)
{
	ft_putstr_fd("Error\n", 1);
	exit (1);
}
