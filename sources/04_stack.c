/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:30:51 by feralves          #+#    #+#             */
/*   Updated: 2023/01/29 18:49:56 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//adicionar os valores recebidos no stack A
void	fill_stack(t_stack *stack, char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		ft_add_back(stack, ft_new_node(ft_atoi(argv[i])));
		i++;
	}
}

//verificar se o stack A está ordenado
//se estiver ordenado, não precisa fazer nada
//se não estiver ordenado, chama o algoritmo escolhido