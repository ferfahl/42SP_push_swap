/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:14:54 by feralves          #+#    #+#             */
/*   Updated: 2023/02/21 20:03:29 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

// Libraries
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
} t_bool;

// Structs
typedef struct s_data
{
	int index;
	int value;
	struct s_data *next;
} t_data;

typedef struct s_node
{
	long int data;
	struct s_node *next;
	struct s_node *prev;
} t_node;

typedef struct stack
{
	int size;
	struct s_node *first;
	struct s_node *last;

} t_stack;

// Define
#define INT_MIN -2147483648
#define INT_MAX 2147483647

// Functions
// checking functions
int check_int(char **argv);
void ft_print_stack(t_stack *stack_a);
void print_list_test(t_data **list);

// fill list/stack with args
void start_push(int argc, char **argv);
void fill_stack(t_stack *stack, t_data *list);
void start_stack(t_data **list);

// //Moving functions
// void	ft_swap(int *a, int *b);
// void	ft_rotate(t_stack **stack);
// void	ft_add_back(t_stack **stack, t_node *new);
// void	ft_add_front(t_stack **stack, t_node *new);

// Error functions
void error_simple(void);
void if_error(void *data, char a);
void ft_free_stack(t_stack *stack);
void ft_free_list(t_data **list);
void ft_clear_node(t_node *node);

// Libft modified functions
t_node *ft_new_node(int number);
void ft_add_back(t_stack *stack, t_node *new);

#endif
