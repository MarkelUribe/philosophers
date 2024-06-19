/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:29:15 by muribe-l          #+#    #+#             */
/*   Updated: 2024/06/19 21:20:55 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/* Waits to lock both forks and eats */
void	philo_eat(t_philo *philo)
{
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;

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
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->n_meals++;
	pthread_mutex_unlock(&philo->meal_mutex);
	pthread_mutex_unlock(l_fork);
	pthread_mutex_unlock(r_fork);
}

/* Waits the time that takes to sleep */
void	philo_sleep(t_philo *philo)
{
	if (dinner_ended(philo->data))
		return ;
	print_message("is sleeping", philo, philo->id);
	ft_usleep(philo->data->time_to_sleep);
}

/* Prints that is thinking and waits to take a fork */
void	philo_think(t_philo *philo)
{
	if (is_dead(philo) || dinner_ended(philo->data))
		return ;
	print_message("is thinking", philo, philo->id);
}

/* Starts the philosophers routine */
void	*routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	if (p->id % 2 == 0)
		ft_usleep(p->data->time_to_eat / 2);
	while (!is_dead(p) && !dinner_ended(p->data))
	{
		philo_eat(p);
		if (is_dead(p) || dinner_ended(p->data))
			break ;
		philo_sleep(p);
		if (is_dead(p) || dinner_ended(p->data))
			break ;
		philo_think(p);
	}
	return (NULL);
}
