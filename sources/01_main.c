/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:55:14 by feralves          #+#    #+#             */
/*   Updated: 2023/02/15 21:51:16 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//como eu retorno a lista se existir?
void	check_if_list(char *argv[])
{
	char	*temp;
	char	**list_temp;

	temp = argv[1]
	list_temp = ft_split(temp, " ");
	if (list_temp)
		return (list_temp);
	error_simple();
}

//checa argumentos não suficientes, chega se 1 argumento só é uma lista
//se não for uma lista, mas for um número, retorna o numero
//se for lista, coloca em um **
void check_args(int argc, char *argv[])
{
	if (argc < 1)
		return(1);
	else if (argc == 1)
		check_if_list(argv);
	return (0);
}

//checa argumentos
//chama o programa
int	main(int argc, char *argv[])
{
	check_args(argc, argv);
	start_push(argc, argv);
	return (0);
}


