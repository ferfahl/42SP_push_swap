/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:09:56 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 01:51:45 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
*@brief prints the stack from first to last and from last to first
*@param stack the stack to be printed
*@return none
*/
void	ft_print_stack(t_stack *stack)
{
	t_node	*aux;

	aux = stack->first;
	ft_printf("first->last\n");
	while (aux)
	{
		ft_printf("%d ", aux->data);
		aux = aux->next;
	}
	aux = stack->last;
	ft_printf("\n");
	ft_printf("last->first\n");
	while (aux)
	{
		ft_printf("%d ", aux->data);
		aux = aux->prev;
	}
	ft_printf("\n");
}

/**
*@brief prints the stack from first to last
*@param stack the stack to be printed
*@return none
*/
void	ft_print_stack_simple(t_stack *stack)
{
	t_node	*aux;

	aux = stack->first;
	ft_printf("stack a\n");
	while (aux)
	{
		ft_printf("%d ", aux->data);
		aux = aux->next;
	}
	ft_printf("\n");
}

/**
*@brief prints the list with the values and indexes
*@param list the list to be printed
*@return none
*/
void	print_list_test(t_data **list)
{
	while (*list)
	{
		ft_printf("value: %d, index: %d\n", (*list)->value, (*list)->index);
		(*list) = (*list)->next;
	}
}
