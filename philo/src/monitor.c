/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:28:25 by muribe-l          #+#    #+#             */
/*   Updated: 2024/06/20 13:56:00 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/* Cheks if dinner ended so that the program finishes */
int	dinner_ended(t_data *data)
{
	pthread_mutex_lock(&data->table_mutex);
	if (data->dinner_ended)
		return (pthread_mutex_unlock(&data->table_mutex), 1);
	return (pthread_mutex_unlock(&data->table_mutex), 0);
}

/* Checks if this philo is dead */
int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	if (philo->dead)
		return (pthread_mutex_unlock(&philo->meal_mutex), 1);
	else if (get_time() - philo->last_meal >= philo->data->time_to_die)
	{
		philo->dead = 1;
		print_message(ADMIN"died"RESET, philo, philo->id);
		pthread_mutex_lock(&philo->data->table_mutex);
		print_message("Dinner finished", philo, 0);
		philo->data->dinner_ended = 1;
		pthread_mutex_unlock(&philo->data->table_mutex);
		return (pthread_mutex_unlock(&philo->meal_mutex), 1);
	}
	return (pthread_mutex_unlock(&philo->meal_mutex), 0);
}

/* Returns 1 if every philo ate the specified minimum number by parameter */
int	everyone_ate(t_philo *philos, int n_philos)
{
	int	i;
	int	meals;

	if ((int)philos->data->times_philo_must_eat == -1)
		return (0);
	i = 0;
	meals = 0;
	while (i < n_philos)
	{
		if (philos[i].n_meals >= (int)philos->data->times_philo_must_eat)
			meals++;
		i++;
	}
	if (meals == n_philos)
	{
		pthread_mutex_lock(&philos->data->print_mutex);
		printf("Every philosopher eat at least %d times\n",
			(int)philos->data->times_philo_must_eat);
		pthread_mutex_unlock(&philos->data->print_mutex);
		return (1);
	}
	return (0);
}

/* Monitors that all the philosophers are alive */
void	*monitor(void *philos)
{
	t_philo	*p;

	p = (t_philo *)philos;
	while (!dinner_ended(p->data) && !everyone_ate(p, p->data->n_philo))
		usleep(1);
	return (philos);
}
