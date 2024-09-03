/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:48:08 by muribe-l          #+#    #+#             */
/*   Updated: 2024/09/03 12:32:45 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/* Initializes threads and starts the routine*/
void	init_threads(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_create(&philos[i].thread, NULL, routine, &philos[i]) != 0)
			destroy_all("Philosopher thread creation error.", philos, data);
		i++;
	}
	if (pthread_create(&data->monitor, NULL, monitor, &philos[0]) != 0)
		destroy_all("Monitor thread creation error.", philos, data);
	i = -1;
	while (++i < data->n_philo)
		pthread_join(philos[i].thread, NULL);
	pthread_join(data->monitor, NULL);
}

/* Initializes all the philosophers and the forks. */
void	init_philos(t_philo **philos, t_data *data)
{
	int	i;

	i = 0;
	*philos = (t_philo *)malloc(sizeof(t_philo) * data->n_philo);
	if (!*philos)
		destroy_all("Malloc error", *philos, data);
	memset(*philos, 0, sizeof(t_philo) * data->n_philo);
	while (i < data->n_philo)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].dead = 0;
		(*philos)[i].data = data;
		(*philos)[i].n_meals = 0;
		(*philos)[i].last_meal = data->start_time;
		if (pthread_mutex_init(&(*philos)[i].meal_mutex, NULL) != 0)
			destroy_all("Mutex init error", *philos, data);
		i++;
	}
}

/* Initializes the fork mutexes */
static void	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			destroy_data("Mutex init error", data);
		i++;
	}
}

/* 
Inserts the parameters into the data structure instance, 
which every philo will point to and mallocs and starts the forks.
*/
void	init_data(int argc, char **argv, t_data *data)
{
	data->n_philo = ft_atoi(argv[1]);
	data->start_time = get_time();
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->dinner_ended = 0;
	if (argc == 6)
		data->times_philo_must_eat = ft_atoi(argv[5]);
	else
		data->times_philo_must_eat = -1;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!data->forks)
		destroy_data("Forks malloc error.", data);
	init_forks(data);
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		destroy_data("Mutex init error", data);
	if (pthread_mutex_init(&data->table_mutex, NULL) != 0)
		destroy_data("Mutex init error", data);
	if (pthread_mutex_init(&data->death_mutex, NULL) != 0)
		destroy_data("Mutex init error", data);
}
