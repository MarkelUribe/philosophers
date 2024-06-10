/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:29:15 by muribe-l          #+#    #+#             */
/*   Updated: 2024/06/10 19:08:36 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void   eat(t_philo *philo)
{

}

void   sleep(t_philo *philo)
{

}

void   think(t_philo *philo)
{
    print_message("is thinking\n", philo, philo->id);
}

void	routine(t_philo *philo)
{
	while (1)
	{
		if (philo->dead)
			break ;
	}
}
