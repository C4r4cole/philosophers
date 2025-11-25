/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:53:36 by fmoulin           #+#    #+#             */
/*   Updated: 2025/11/25 18:03:42 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	main (int argc, char **argv)
{
	t_table table;
	
	if (argc == 5 || argc == 6)
	{
		// Le nombre d'arguments est correct
		// 1) errors checking, filling table data
			parse_input(&table, *argv);
			
		// 2) creating philosophers, mallocking philosophers, etc.
			data_init(&table);
		
		// 3) Start actual simulation
			dinner_start(&table);

		// 4) No leaks, cleaning everything
		// The simulation end when all philos are full or if one dies
			// clean(&table);

	}
	else
	{
		// une fonction qui print une erreur et qui exit le programme
		error_exit("Wrong input :\n a correct input could be ./philo 5 800 200 200 [5]");
	}
}