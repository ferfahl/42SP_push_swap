/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:07:56 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 01:23:22 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
*@brief checks if there are enough arguments, if there are, checks if they are
*numbers
*@param argc the number of arguments
*@param argv the arguments
*@return none
*/
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

/**
*@brief checks args and starts the program
*@param argc the number of arguments
*@param argv the arguments
*@return none
*/
int	main(int argc, char *argv[])
{
	check_args(argc, argv);
	start_push(argc, argv);
	return (0);
}
