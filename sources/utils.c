/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:52:08 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 01:37:51 by mcarecho         ###   ########.fr       */
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

void	push(t_stack *source, t_stack *dest, char a_or_b)
{
	t_node	*temp;

	if (!source->first)
		return ;
	temp = source->first->next;
	temp->prev = NULL;
	ft_add_front(dest, source->first);
	source->first = temp;
	source->size -= 1;
	if (a_or_b == 'a')
		ft_putstr_fd("pa\n", 2);
	else if (a_or_b == 'b')
		ft_putstr_fd("pb\n", 2);
}

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

// retorna sucesso
	// print_list_test(temp);
void	success_exit(void *temp)
{
	ft_free_list(temp);
	exit (0);
}
