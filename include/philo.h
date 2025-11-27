/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:53:27 by fmoulin           #+#    #+#             */
/*   Updated: 2025/11/27 10:51:25 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <limits.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

// ************************ //
//           ENUMS          //
// ************************ //

typedef enum e_philo_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}						t_philo_status;

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}						t_opcode;

typedef enum e_time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}						t_time_code;

// ************************ //
//        STRUCTURES        //
// ************************ //

typedef pthread_mutex_t	t_mtx;
typedef struct s_table	t_table;

typedef struct s_fork
{
	t_mtx				fork;
	int					fork_id;
}						t_fork;

typedef struct s_philo
{
	int					id;
	long				meals_counter;
	bool				full;
	long				last_meal_time;
	t_fork				*first_fork;
	t_fork				*second_fork;
	pthread_t			thread_id;
	t_mtx				philo_mutex;
	t_table				*table;
}						t_philo;

typedef struct s_table
{
	long				philo_nbr;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				nbr_limit_meals;
	long				start_simulation;
	bool				end_simulation;
	bool				all_thread_ready;
	long				threads_running_nbr;
	pthread_t			monitor;
	t_mtx				table_mutex;
	t_mtx				write_mutex;
	t_fork				*forks;
	t_philo				*philos;
}						t_table;

// ************************ //
//        FUNCTIONS         //
// ************************ //

/* utils.c */
void					error_exit(char *error);
void					precise_usleep(long usec, t_table *table);
void					clean(t_table *table);

/* parsing.c */
void					parse_input(t_table *table, char **argv);

/* safe_functions */
void					*safe_malloc(size_t bytes);
void					safe_mutex_handle(t_mtx *mutex, t_opcode opcode);
void					safe_thread_handle(pthread_t *thread,
							void *(*foo)(void *), void *data, t_opcode opcode);

/* init.c */
void					data_init(t_table *table);

/* getters_setters.c */
void					set_bool(t_mtx *mutex, bool *dest, bool value);
bool					get_bool(t_mtx *mutex, bool *value);
void					set_long(t_mtx *mutex, long *dest, long value);
long					get_long(t_mtx *mutex, long *value);
bool					simulation_finished(t_table *table);

/* synchro_utils.c */
void					wait_all_threads(t_table *table);
bool					all_threads_running(t_mtx *mutex, long *threads,
							long philo_nbr);
void					increase_long(t_mtx *mutex, long *value);
void					de_synchronize_philos(t_philo *philo);

/* time.c */
long					get_time(t_time_code time_code);

/* write.c */
void					write_status(t_philo_status status, t_philo *philo);

/* dinner.c */
void					dinner_start(t_table *table);
void					*dinner_simulation(void *data);
void					thinking(t_philo *philo, bool pre_simulation);

/* monitoring.c */
void *monitor_dinner(void *data);
