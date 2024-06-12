/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:28:25 by muribe-l          #+#    #+#             */
/*   Updated: 2024/06/12 14:00:56 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

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

/* Monitors that all the philosophers are alive */
void	*monitor(void *philos)
{
	int	i;
	t_philo *p;

	p = (t_philo *)philos;
	while (!p[0].data->dinner_ended)
	{
		i = -1;
		while (++i < p[0].data->n_philo)
		{
			if (is_dead(&p[i]))
				p[0].data->dinner_ended = 1;
		}
	}
	return (NULL);
}
