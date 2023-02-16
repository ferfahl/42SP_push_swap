/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:02:49 by feralves          #+#    #+#             */
/*   Updated: 2023/02/15 22:28:35 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//verificar se os valores são inteiros
int	check_int(char **argv)
{
    int i;
    int j;
    
    i = 1;
    while(argv[i])
    {
        j = 0;
        if (argv[i][j] == '-' || argv[i][j] == '+')
            j++;
        while(argv[i][j])
        {
            if (!ft_isdigit(argv[i][j]))
                error_simple();
            j++;
        }
        i++;
    }
    return (1);
}

// //verificar se os valores são únicos
// void	check_double(t_stack stack)
// {

// }

// //verificar int max/min
// void	check_range(t_stack stack)
// {

// }

// void    check_stack(t_stack *stack)
// {
//     t_node *temp;
    
//     while(stack->first)
//     {
//         temp = stack->first->data;
        
//     }
// }

