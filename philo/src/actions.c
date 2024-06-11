/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:29:15 by muribe-l          #+#    #+#             */
/*   Updated: 2024/06/11 16:19:15 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void   eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	print_message("has taken a fork", philo, philo->id);

}

void   sleep(t_philo *philo)
{

}

void	think(t_philo *philo)
{
	print_message("is thinking", philo, philo->id);
}

void	routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(1);
	while (!is_dead(philo))
	{
		
	}
}
