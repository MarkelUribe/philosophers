/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:35:24 by muribe-l          #+#    #+#             */
/*   Updated: 2024/06/10 18:41:19 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/* Destroy all the elements and stop the program */
void	destroy_all(char *error, t_philo *philos, t_data *data)
{
	int i;
	
	i = 0;
	write(2, error, ft_strlen(error));
	while (i < data->n_philo)
	{
		if (&philos[i].fork)
			pthread_mutex_destroy(&philos[i].fork);
		if (&philos[i].thread)
			pthread_mutex_destroy(&philos[i].thread);
		i++;
	}
}
