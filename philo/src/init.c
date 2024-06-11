/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:48:08 by muribe-l          #+#    #+#             */
/*   Updated: 2024/06/11 15:28:35 by muribe-l         ###   ########.fr       */
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
		if (pthread_create(&philos[i].thread, NULL, &routine, &philos[i]) != 0)
			destroy_all("Thread creation error.", philos, data);
		i++;
	}
}

/* Initializes all the philosophers and the forks. */
void	init_philos(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		philos[i].id = i + 1;
		philos[i].dead = 0;
		philos[i].data = data;
		philos[i].last_meal = data->start_time;
		pthread_mutex_init(&philos[i].fork, NULL);
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
	data->start_time = get_time();
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->times_philo_must_eat = ft_atoi(argv[5]);
	else
		data->times_philo_must_eat = -1;
}
