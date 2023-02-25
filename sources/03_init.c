/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:20:09 by feralves          #+#    #+#             */
/*   Updated: 2023/02/25 05:32:57 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// adiciona um nó no final da lista
t_data	*add_node_value(long int number, int i)
{
	t_data	*new_node;

	new_node = (t_data *)malloc(sizeof(t_data));
	if (!new_node)
		error_simple();
	new_node->value = number;
	new_node->next = NULL;
	new_node->index = i;
	return (new_node);
}

// verifica se o número já existe na lista
// se não existir, adiciona o nó no final da lista, colocando o index dele de
// acordo com o valor maior ou menor
void	add_next_node(t_data **list, long int number, int i)
{
	t_data	*temp;

	temp = *list;
	if (number > INT_MAX || number < INT_MIN)
		if_error(list, 'l');
	while (temp)
	{
		if (temp->value == number)
			if_error(list, 'l');
		if (temp->value > number)
			temp->index++;
		else
			i++;
		if (!temp->next)
			break ;
		temp = temp->next;
	}
	temp->next = add_node_value(number, i);
}

// cria a lista com os valores passados como argumentos
void	init_list(int argc, char **argv, t_data **list)
{
	int	i;

	i = 1;
	if (*list == NULL)
		*list = add_node_value((ft_atoi_mod(argv[i])), 1);
	while (++i < argc)
		add_next_node(list, (ft_atoi_mod(argv[i])), 1);
}
// print_list_test(list);

// iniciar o programa
void	start_push(int argc, char **argv)
{
	t_data	**temp;

	temp = (t_data **)ft_calloc(1, sizeof(t_data *));
	if (!temp)
		error_simple();
	init_list(argc, argv, temp);
	if (check_sorted(*temp))
		success_exit(temp);
	start_stack(temp);
}
	// ft_free_list(temp);
