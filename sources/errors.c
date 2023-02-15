/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:42:17 by feralves          #+#    #+#             */
/*   Updated: 2023/02/15 21:09:56 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//função para limpar algum tipo de arquivo
void	if_error(void *data)
{
	ft_putstr_fd("Error", 2);
	ft_free(data);
	exit (1);
}

void	error_simple(void)
{
	ft_putstr_fd("Error", 2);
	exit (1);
}
