/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:29:15 by muribe-l          #+#    #+#             */
/*   Updated: 2024/09/03 12:39:10 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/* Checks if they are dead and returns the result */
int	am_i_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	if (philo->dead)
		return (pthread_mutex_unlock(&philo->data->death_mutex), 1);
	return (pthread_mutex_unlock(&philo->data->death_mutex), 0);
}

/* In case that there is a singe philo, wait till it dies */
static int	single_philo(t_philo *philo)
{
	if (philo->data->n_philo <= 1)
	{
		print_message("has taken a fork", philo, philo->id);
		while (!am_i_dead(philo))
			usleep(42);
		return (1);
	}
	return (0);
}

/* Waits until both forks are free and eats */
void	philo_eat(t_philo *philo)
{
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;

	if (single_philo(philo))
		return ;
	l_fork = &philo->data->forks[philo->id - 1];
	pthread_mutex_lock(l_fork);
	print_message("has taken a fork", philo, philo->id);
	if (philo->id == philo->data->n_philo)
		r_fork = &philo->data->forks[0];
	else
		r_fork = &philo->data->forks[philo->id];
	pthread_mutex_lock(r_fork);
	print_message("has taken a fork", philo, philo->id);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->meal_mutex);
	print_message("eating", philo, philo->id);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->n_meals++;
	pthread_mutex_unlock(&philo->meal_mutex);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(l_fork);
	pthread_mutex_unlock(r_fork);
}

/* Waits the time that takes to sleep */
void	philo_sleep(t_philo *philo)
{
	if (am_i_dead(philo))
		return ;
	print_message("is sleeping", philo, philo->id);
	ft_usleep(philo->data->time_to_sleep);
}

/* Starts the philosophers routine */
void	*routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	if (p->id % 2 == 0)
		ft_usleep(p->data->time_to_eat / 2);
	while (!am_i_dead(p))
	{
		philo_eat(p);
		if (am_i_dead(p))
			break ;
		philo_sleep(p);
		if (am_i_dead(p))
			break ;
		print_message("is thinking", p, p->id);
	}
	return (philo);
}
