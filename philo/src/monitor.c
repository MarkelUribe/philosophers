/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:28:25 by muribe-l          #+#    #+#             */
/*   Updated: 2024/09/03 17:25:05 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/* Kills all the philosophers at once */
void	kill_all(t_philo *philos)
{
	t_data	*data;
	int		i;

	data = philos->data;
	i = -1;
	pthread_mutex_lock(&data->death_mutex);
	while (++i < data->n_philo)
		philos[i].dead = 1;
	pthread_mutex_unlock(&data->death_mutex);
}

/* Checks if any philo should die */
int	is_anyone_dead(t_philo *philos)
{
	t_data	*data;
	int		i;

	data = philos->data;
	i = -1;
	while (++i < data->n_philo)
	{
		pthread_mutex_lock(&philos[i].meal_mutex);
		if (get_time() - philos[i].last_meal >= data->time_to_die)
		{
			print_message(ADMIN"died"RESET, &philos[i], philos[i].id);
			pthread_mutex_lock(&philos->data->table_mutex);
			data->dinner_ended = 1;
			pthread_mutex_unlock(&philos->data->table_mutex);
			kill_all(philos);
			return (pthread_mutex_unlock(&philos[i].meal_mutex), 1);
		}
		pthread_mutex_unlock(&philos[i].meal_mutex);
	}
	return (0);
}

/* Returns 1 if every philo ate the specified minimum amount by the parameter */
int	everyone_ate(t_philo *philos, int n_philos)
{
	int	i;
	int	meals;

	if ((int)philos->data->times_philo_must_eat == -1)
		return (0);
	i = -1;
	meals = 0;
	while (++i < n_philos)
	{
		pthread_mutex_lock(&philos[i].meal_mutex);
		meals += philos[i].n_meals >= (int)philos->data->times_philo_must_eat;
		pthread_mutex_unlock(&philos[i].meal_mutex);
	}
	if (meals == n_philos)
	{
		pthread_mutex_lock(&philos->data->table_mutex);
		philos->data->dinner_ended = 1;
		pthread_mutex_unlock(&philos->data->table_mutex);
		pthread_mutex_lock(&philos->data->print_mutex);
		printf("Every philosopher eat at least %d times\n",
			(int)philos->data->times_philo_must_eat);
		pthread_mutex_unlock(&philos->data->print_mutex);
		return (kill_all(philos), 1);
	}
	return (0);
}

/* Monitors that all the philosophers are alive */
void	*monitor(void *philos)
{
	t_philo	*p;

	p = (t_philo *)philos;
	while (1)
	{
		if (is_anyone_dead(p) || everyone_ate(p, p->data->n_philo))
			break ;
		ft_usleep(5);
	}
	return (philos);
}
