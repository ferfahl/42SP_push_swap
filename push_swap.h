/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:14:54 by feralves          #+#    #+#             */
/*   Updated: 2023/01/28 21:36:51 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//Libraries
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

//Structs
typedef struct s_data
{
	int		index;
	int		status;
}				t_data;

typedef struct stack
{
	int		*stack_a;
	int		*stack_b;
	int		size_a;
	int		size_b;
}				t_stack;

typedef struct s_node
{
	t_data			data;
	struct s_node	*next;
}				t_node;

//Define
# define INT_MIN -2147483648
# define INT_MAX 2147483647

//Functions

#endif
