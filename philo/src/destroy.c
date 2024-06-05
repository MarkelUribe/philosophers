/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:35:24 by muribe-l          #+#    #+#             */
/*   Updated: 2024/06/05 16:59:14 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	destroy_all(t_philo *philos, t_data *data)
{
	int i;
	
	i = 0;
	while (i < data->n_philo)
	{
		if (&philos[i].fork)
			pthread_mutex_destroy(&philos[i].fork);
		if (&philos[i].thread)
			pthread_mutex_destroy(&philos[i].thread);
		i++;
	}
}