/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:35:24 by muribe-l          #+#    #+#             */
/*   Updated: 2024/06/20 13:37:23 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/* Destroy all the elements and stops the program */
void	destroy_all(char *error, t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	if (ft_strlen(error) != 0)
		printf(ADMIN"Error: %s\n"RESET, error);
	while (i < data->n_philo)
	{
		if (&data->forks[i])
		pthread_mutex_destroy(&data->forks[i]);
		if (&philos[i].meal_mutex)
			pthread_mutex_destroy(&philos[i].meal_mutex);
		i++;
	}
	if (&data->print_mutex)
		pthread_mutex_destroy(&data->print_mutex);
	if (&data->table_mutex)
		pthread_mutex_destroy(&data->table_mutex);
	if (data->forks != NULL)
		free(data->forks);
	if (philos != NULL)
		free(philos);
	exit(1);
}

/* Destroys all the data if there was an error when init */
void	destroy_data(char *error, t_data *data)
{
	int	i;

	i = 0;
	if (ft_strlen(error) != 0)
		printf(ADMIN"Error: %s\n"RESET, error);
	while (i < data->n_philo)
	{
		if (&data->forks[i])
			pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	if (&data->print_mutex)
		pthread_mutex_destroy(&data->print_mutex);
	if (&data->table_mutex)
		pthread_mutex_destroy(&data->table_mutex);
	if (data->forks != NULL)
		free(data->forks);
	exit(1);
}
