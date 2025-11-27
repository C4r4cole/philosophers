/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:53:52 by fmoulin           #+#    #+#             */
/*   Updated: 2025/11/27 11:16:30 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	precise_usleep(long usec, t_table *table)
{
	long	start;
	long	elapsed;
	long	remain;
	
	start = get_time(MICROSECOND);
	while (get_time(MICROSECOND) - start < usec)
	{
		if (simulation_finished(table))
			break ;
		elapsed = get_time(MICROSECOND) - start;
		remain = usec - elapsed;
		if (remain > 1e3)
			usleep(remain / 2);
		else
		{
			while (get_time(MICROSECOND) - start < usec)
				;
		}
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

void error_exit(char *error)
{
	printf("%s\n", error);
	exit(EXIT_FAILURE);
}
