/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:52:08 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 01:55:27 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_swap(int *a, int *b)
// {
// 	int temp;

// 	temp = *a;
// 	*a = *b;
// 	*b = temp;
// }

// // void	ft_print_moves(char *move)
// // {
// // 	if (move = )
// // 	ft_putstr_fd(move, 1);
// // }

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
