/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:52:08 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 02:25:51 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
*@brief push the first element of the stack a to the stack b
*@param stack_a the stack to be pushed
*@param stack_b the stack to receive the element
*@return none
*/
void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	ft_push(stack_b, stack_a, 'a');
}

/**
*@brief push the first element of the stack b to the stack a
*@param stack_a the stack to receive the element
*@param stack_b the stack to be pushed
*@return none
*/
void	ft_pb(t_stack *stack_a, t_stack *stack_b)
{
	ft_push(stack_a, stack_b, 'b');
}

/**
*@brief clear values of the node
*@param node the node to be cleared
*@return none
*/
void	ft_clear_node(t_node *node)
{
	t_node	*aux;

	if (node == NULL)
		return ;
	while (node)
	{
		aux = node->next;
		node->next = NULL;
		node->prev = NULL;
		free(node);
		node = aux;
	}
}

/**
*@brief returns if the stack is sorted
*@param temp the list to be cleared
*@return none
*/
void	success_exit(void *temp)
{
	ft_free_list(temp);
	exit (0);
}
