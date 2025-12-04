/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:53:52 by fmoulin           #+#    #+#             */
/*   Updated: 2025/12/04 13:33:02 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	precise_msleep(long ms, t_table *table)
{
	long	start;

	start = get_time(MILLISECOND);
	while (!simulation_finished(table))
	{
		if (get_time(MILLISECOND) - start >= ms)
			break ;
		usleep(100);
	}
}

void	clean(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < table->philo_nbr)
	{
		philo = table->philos + i;
		safe_mutex_handle(&philo->philo_mutex, DESTROY);
		i++;
	}
	safe_mutex_handle(&table->table_mutex, DESTROY);
	safe_mutex_handle(&table->write_mutex, DESTROY);
	free(table->forks);
	free(table->philos);
}

void	error_exit(char *error)
{
	printf("%s\n", error);
	exit(EXIT_FAILURE);
}
