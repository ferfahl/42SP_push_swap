/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:09:56 by feralves          #+#    #+#             */
/*   Updated: 2023/02/25 18:55:38 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

//imprime a lista com index para verificação
void	print_list_test(t_data **list)
{
	while (*list)
	{
		ft_printf("value: %d, index: %d\n", (*list)->value, (*list)->index);
		(*list) = (*list)->next;
	}
}
