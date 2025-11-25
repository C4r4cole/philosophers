/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:53:52 by fmoulin           #+#    #+#             */
/*   Updated: 2025/11/25 18:06:34 by fmoulin          ###   ########.fr       */
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

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void error_exit(char *error)
{
	ft_putstr_fd(error, 2);
	exit(EXIT_FAILURE);
}
