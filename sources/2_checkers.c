/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_checkers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:02:49 by feralves          #+#    #+#             */
/*   Updated: 2023/01/06 16:03:04 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_int(char *argv[])
{
	verificar o que eu recebo para ver se é um int
	INT_MIN e INT_MAX
}

int check_args(int argc, char *argv[])
{
	if (argc < 1)
		if_error("Not enough arguments");
	else if (argc == 1)
		return (1);
	else
		check_int(argv);
	return (0);
}