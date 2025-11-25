/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchro_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:16:51 by fmoulin           #+#    #+#             */
/*   Updated: 2025/11/25 11:45:57 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	wait_all_threads(t_table *table)
{
	while (!get_bool(&table->table_mutex, &table->all_thread_ready))
		;
}