/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:48:08 by muribe-l          #+#    #+#             */
/*   Updated: 2024/06/10 18:42:12 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/* Creates, initializes and assigns fork mutex to philo */
static void	add_mutex(t_philo *philo)
{
	pthread_mutex_t	fork;
	
	pthread_mutex_init(&fork, NULL);
	philo->fork = fork;
}

/* Initializes threads and starts the routine*/
void	init_threads(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_create(&philos[i].thread, NULL, &routine, &philos[i]) != 0)
			destroy_all("Thread creation error.", philos, data);
		i++;
	}
}

/* Initializes all the philosophers. */
void	init_philos(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		philos[i].id = i + 1;
		philos[i].dead = 0;
		philos[i].data = data;
		add_mutex(&philos[i]);
		i++;
	}
}

/* 
Inserts the parameters into the data structure instance, 
which every philo will point to.
*/
void	init_data(int argc, char **argv, t_data *data)
{
	data->n_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->times_philo_must_eat = ft_atoi(argv[5]);
	else
		data->times_philo_must_eat = -1;
}
