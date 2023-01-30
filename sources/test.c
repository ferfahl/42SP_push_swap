/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:09:56 by feralves          #+#    #+#             */
/*   Updated: 2023/01/30 22:49:06 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack_a)
{
	t_node	*aux;

	aux = stack_a->first;
	ft_printf("first->last\n");
	while (aux)
	{
		ft_printf("%d ", aux->data);
		aux = aux->next;
	}
	aux = stack_a->last;
	ft_printf("\n");
	ft_printf("last->first\n");
	while (aux)
	{
		ft_printf("%d ", aux->data);
		aux = aux->prev;
	}
	ft_printf("\n");
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	stack_a = (t_stack *)calloc(1, sizeof(t_stack));
	if (!stack_a)
		return (0);
	fill_stack(stack_a, argv);
	ft_print_stack(stack_a);
	(void)argc;
	return (0);
}
