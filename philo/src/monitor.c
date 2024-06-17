/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markel <markel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:28:25 by muribe-l          #+#    #+#             */
/*   Updated: 2024/06/17 15:31:50 by markel           ###   ########.fr       */
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
		return (pthread_mutex_unlock(&philo->meal_mutex), 1);
	}
	return (pthread_mutex_unlock(&philo->meal_mutex), 0);
}

/* Returns 1 if every philo ate the specified minimum number by parameter */
int	everyone_ate(t_philo **philos)
{
	int	i;
	int	meals;

	if ((int)(*philos)->data->times_philo_must_eat == -1)
		return (0);
	i = 0;
	meals = 0;
	while (i < (*philos)->data->n_philo)
	{
		if ((*philos)[i].n_meals >= (int)(*philos)->data->times_philo_must_eat)
			meals++;
		i++;
	}
	if (meals == (*philos)->data->n_philo)
	{
		printf("Every philosopher eat %dtimes\n",
			(int)(*philos)->data->times_philo_must_eat);
		return (1);
	}
	return (0);
}

/* Iterate all philosophers */
void	iter_philos(t_philo **p)
{
	int	i;
	
	while (!dinner_ended((*p)[0].data))
	{
		i = -1;
		while (++i < (*p)[0].data->n_philo)
		{
			if (is_dead(&(*p)[i]))
			{
				pthread_mutex_lock(&(*p)->data->table_mutex);
				printf("Dinner finished\n");
				(*p)[0].data->dinner_ended = 1;
				pthread_mutex_unlock(&(*p)->data->table_mutex);
			}
		}
	}
}

/* Monitors that all the philosophers are alive */
void	*monitor(void *philos)
{
	iter_philos((t_philo **)&philos);
	return (NULL);
}
