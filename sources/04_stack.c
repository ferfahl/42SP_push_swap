/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:30:51 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 21:01:31 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
*@brief adds the values received in list separated in stack
*@param stack the stack to be filled
*@param list the list with the values to be added
*@return none
*/
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

/**
*@brief initializes the stack with NULL value
*@param stack the stack to be initialized
*@return none
*/
void	init_stack(t_stack *stack)
{
	stack->first = NULL;
	stack->last = NULL;
	stack->size = 0;
}

/**
*@brief initializes the stacks and calls the functions to fill the stacks
*@param list the list with the values to be added
*@return none
*/
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
	ft_free_list(list);
	init_stack(stack_b);
	ft_moves_like(stack_a, stack_b);
	ft_algorithm(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
}

// função
// 	verifica stack_a < 5
// 		stack_a -> 2
// 		stack_a -> 3
// 		stack_a -> 4
// 	enquanto stack_a > 5
// 		o negocio dos 30%
// 	fazer um sort especifico nosso pra 5
