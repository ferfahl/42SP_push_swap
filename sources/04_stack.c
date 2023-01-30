/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:30:51 by feralves          #+#    #+#             */
/*   Updated: 2023/01/30 22:41:56 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//adicionar os valores recebidos no stack A
//transformar os valores em inteiros
void	fill_stack(t_stack *stack, char **argv)
{
	int i;
	int	temp;
	t_node *new_node;

	i = 1;
	while (argv[i])
	{
		temp = ft_atoi_mod(argv[i]);
		new_node = ft_new_node(temp);
		ft_add_back(stack, new_node);
		i++;
	}
}

//verificar se o stack A está ordenado
//se estiver ordenado, não precisa fazer nada
//se não estiver ordenado, chama o algoritmo escolhido
