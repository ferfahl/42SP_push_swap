/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:14:54 by feralves          #+#    #+#             */
/*   Updated: 2023/02/15 23:05:30 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//Libraries
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

//Structs
// typedef struct s_data
// {
// 	int		index;
// 	int		status;
// }				t_data;

typedef struct s_node
{
	long int		data;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct stack
{
	int				size;
	struct s_node	*first;
	struct s_node	*last;

}				t_stack;

//Define
# define INT_MIN -2147483648
# define INT_MAX 2147483647

//Functions
//checking functions
int	check_int(char **argv);
void	ft_print_stack(t_stack *stack_a);


//fill stack with args
void	start_push(char **argv);
void	fill_stack(t_stack *stack, char **rec_list);

// //Moving functions
// void	ft_swap(int *a, int *b);
// void	ft_rotate(t_stack **stack);
// void	ft_add_back(t_stack **stack, t_node *new);
// void	ft_add_front(t_stack **stack, t_node *new);

//Error functions
void	error_simple(void);
void	if_error(void *data);
void	ft_free(t_stack *stack);
void	ft_clear_node(t_node *node);

//Libft modified functions
t_node	*ft_new_node(int number);
void	ft_add_back(t_stack *stack, t_node *new);

#endif
