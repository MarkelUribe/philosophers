/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:29:15 by muribe-l          #+#    #+#             */
/*   Updated: 2024/06/11 19:59:58 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/* Waits to lock both forks and eats */
void	eat(t_philo *philo)
{
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;

	l_fork = &philo->data->forks[philo->id - 1];
	pthread_mutex_lock(&l_fork);
	print_message("has taken a fork", philo, philo->id);
	if (philo->id == philo->data->n_philo)
		r_fork = &philo->data->forks[0];
	else
		r_fork = &philo->data->forks[philo->id];
	pthread_mutex_lock(&r_fork);
	print_message("has taken a fork", philo, philo->id);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->meal_mutex);
	ft_usleep(philo->data->time_to_eat);
	print_message("eating", philo, philo->id);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->n_meals++;
	pthread_mutex_unlock(&philo->meal_mutex);
	pthread_mutex_unlock(&l_fork);
	pthread_mutex_unlock(&r_fork);
}

/* Waits the time that takes to sleep */
void	sleep(t_philo *philo)
{
	print_message("is sleeping", philo, philo->id);
	ft_usleep(philo->data->time_to_sleep);
}

/* Prints that is thinking and waits to take a fork */
void	think(t_philo *philo)
{
	print_message("is thinking", philo, philo->id);
}

/* Starts the philosophers routine */
void	routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(1);
	while (!is_dead(philo))
	{
		eat(philo);
		sleep(philo);
		think(philo);
	}
}
