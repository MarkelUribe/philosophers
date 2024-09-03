/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:29:15 by muribe-l          #+#    #+#             */
/*   Updated: 2024/09/03 15:01:49 by muribe-l         ###   ########.fr       */
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

/* Lock the fork mutexes */
static void	lock_forks(t_philo *philo, pthread_mutex_t *l, pthread_mutex_t *r)
{
	pthread_mutex_lock(l);
	print_message("has taken a fork", philo, philo->id);
	pthread_mutex_lock(r);
	print_message("has taken a fork", philo, philo->id);
}

/* Waits until both forks are free and eats */
void	philo_eat(t_philo *philo)
{
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;

	if (single_philo(philo))
		return ;
	if (philo->id == philo->data->n_philo)
	{
		l_fork = &philo->data->forks[philo->id % philo->data->n_philo];
		r_fork = &philo->data->forks[philo->id - 1];
	}
	else
	{
		l_fork = &philo->data->forks[philo->id - 1];
		r_fork = &philo->data->forks[philo->id % philo->data->n_philo];
	}
	lock_forks(philo, l_fork, r_fork);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_time();
	print_message("is eating", philo, philo->id);
	philo->n_meals++;
	pthread_mutex_unlock(&philo->meal_mutex);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(l_fork);
	pthread_mutex_unlock(r_fork);
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
		print_message("is sleeping", p, p->id);
		ft_usleep(p->data->time_to_sleep);
		if (am_i_dead(p))
			break ;
		print_message("is thinking", p, p->id);
	}
	return (philo);
}
