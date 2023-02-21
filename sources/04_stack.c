/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:30:51 by feralves          #+#    #+#             */
/*   Updated: 2023/02/20 21:03:22 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//adicionar os valores recebidos separados no stack A
void	fill_stack(t_stack *stack, t_data *list)
{
	int			temp;
	t_node		*new_node;

	while (list)
	{
		temp = list->index;
		new_node = ft_new_node(temp);
		ft_add_back(stack, new_node);
		list = list->next;
	}
}

//inicia ambos os stacks como NULL
void	init_stack(t_stack *stack)
{
	stack->first = NULL;
	stack->last = NULL;
	stack->size = 0;
}

//inicia as stacks
void	start_stack(t_data **list)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a)
		error_simple();
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a)
		error_simple();
	init_stack(stack_a);
	fill_stack(stack_a, *list);
	init_stack(stack_b);
	ft_print_stack(stack_a);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	// check_stack(stack_a);
}


// função
// 	verifica stack_a < 5
// 		stack_a -> 2
// 		stack_a -> 3
// 		stack_a -> 4
// 	enquanto stack_a > 5
// 		o negocio dos 30%
// 	fazer um sort especifico nosso pra 5
	
	
//verificar se o stack A está ordenado
//se estiver ordenado, não precisa fazer nada
//se não estiver ordenado, chama o algoritmo escolhido
