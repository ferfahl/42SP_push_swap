/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:20:09 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 01:33:11 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
*@brief adds a node at the end of the list
*@param number the argv number after being converted to long int
*@param i the index of the number
*@return the new node created
*/
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

/**
*@brief verifies if the number already exists in the list, if not, adds the node
*at the end of the list, putting the index of the node according to the greater
*or smaller value
*@param list the list to be checked
*@param number the argv number after being converted to long int
*@param i the index of the number
*@return none
*/
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

/**
*@brief creates the list with the arguments
*@param argc the number of arguments
*@param argv the arguments
*@param list the list to be created
*@return none
*/
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

/**
*@brief starts the list
*@param argc the number of arguments
*@param argv the arguments
*@return none
*/
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
