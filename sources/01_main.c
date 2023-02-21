/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:07:56 by feralves          #+#    #+#             */
/*   Updated: 2023/02/20 20:48:19 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//checa argumentos não suficientes
//se for um número, retorna o numero
//checa demais numeros do argv
void	check_args(int argc, char **argv)
{
	if (argc <= 1)
		exit(0);
	else if (argc == 2)
	{
		if (argv[1] == NULL)
			error_simple();
		if (check_int(argv))
			exit(0);
		else
			error_simple();
	}
	else
	{
		while (argv)
		{
			if (check_int(argv))
				return ;
			else
				error_simple();
		}
	}
} 

//checa argumentos
//chama o programa
int	main(int argc, char *argv[])
{
	check_args(argc, argv);
	start_push(argc, argv);
	return (0);
}
