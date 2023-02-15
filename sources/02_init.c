/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:22:19 by feralves          #+#    #+#             */
/*   Updated: 2023/02/15 21:58:19 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//adicionar os valores recebidos separados no stack A
void	fill_stack(t_stack *stack, char **rec_list)
{
	int i;
	int	temp;
	t_node *new_node;

	i = 1;
	while (rec_list[i])
	{
		new_node = ft_new_node(temp);
		ft_add_back(stack, new_node);
		i++;
	}
}

//inicia ambos os stacks como NULL
void	init_stack(t_stack *stack)
{
	stack->first = NULL;
	stack->last = NULL;
	stack->size = 0;
}

//iniciar as stacks A e B com NULL e size = 0
void	start_push(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a)
		error();
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a)
		error();
	init_stack(stack_a);
	init_stack(stack_b);
	if (vindo de array)
		fill_stack(stack_a, array);
	else
		fill_stack(stack_a, argv);
//	verificar todos os ints no stack a
}
