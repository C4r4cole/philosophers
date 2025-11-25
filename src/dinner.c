/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:53:43 by fmoulin           #+#    #+#             */
/*   Updated: 2025/11/25 11:47:33 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	*dinner_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table);
	return (NULL);
}

void	dinner_start(t_table *table)
{
	int	i;

	i = 0;
	if (table->nbr_limit_meals == 0)
		return ;
	else if (table->philo_nbr == 1)
		; // TODO
	else
	{
		while (i < table->philo_nbr)
		{
			safe_thread_handle(&table->philos[i].thread_id, dinner_simulation, &table->philos[i], CREATE);
			i++;
		}
	}
	set_bool(&table->table_mutex, &table->all_thread_ready, true);
}