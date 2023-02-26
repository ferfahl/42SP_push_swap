/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:14:54 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 00:56:57 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Libraries
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}			t_bool;

// Structs
typedef struct s_data
{
	int				index;
	int				value;
	struct s_data	*next;
}			t_data;

typedef struct s_node
{
	long int		data;
	struct s_node	*next;
	struct s_node	*prev;
}			t_node;

typedef struct stack
{
	int				size;
	struct s_node	*first;
	struct s_node	*last;

}			t_stack;

// Define
# define INT_MIN -2147483648
# define INT_MAX 2147483647

// Functions
// checking functions
int		check_int(char **argv);
void	ft_print_stack(t_stack *stack);
void	ft_print_stack_simple(t_stack *stack);
void	print_list_test(t_data **list);
t_bool	check_sorted(t_data *list);

// fill list/stack with args
void	start_push(int argc, char **argv);
void	fill_stack(t_stack *stack, t_data *list);
void	start_stack(t_data **list);

// //Moving functions
void	ft_swap(int *a, int *b);
void	ft_rotate(t_stack *stack, char a_or_b);
void	ft_reverse_rotate(t_stack *stack, char a_or_b);
void	ft_double_rotate(t_stack *stack_a, t_stack *stack_b);
void	ft_double_reverse_rotate(t_stack *stack_a, t_stack *stack_b);

// Utils for moving
void	ft_add_back(t_stack *stack, t_node *new);
void	ft_add_front(t_stack *stack, t_node *new);

// Testing moves
void	ft_moves_like(t_stack *stack);

// Error functions
void	error_simple(void);
void	if_error(void *data, char a);
void	ft_free_stack(t_stack *stack);
void	ft_free_list(t_data **list);
void	ft_clear_node(t_node *node);

// Success functions
void	success_exit(void *temp);

// Libft modified functions
t_node	*ft_new_node(int number);
void	ft_add_back(t_stack *stack, t_node *new);

#endif
