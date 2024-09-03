/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:35:24 by muribe-l          #+#    #+#             */
/*   Updated: 2024/09/03 12:32:49 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/* Checks if mutex exists and destroys it */
static void	destroy_mutex(pthread_mutex_t *mutex)
{
	if (mutex)
		pthread_mutex_destroy(mutex);
}

/* Destroy all the elements and stops the program */
void	destroy_all(char *error, t_philo *philos, t_data *data)
{
	int	i;

	i = -1;
	if (ft_strlen(error) != 0)
		printf(ADMIN"Error: %s\n"RESET, error);
	while (++i < data->n_philo)
	{
		destroy_mutex(&data->forks[i]);
		destroy_mutex(&philos[i].meal_mutex);
	}
	destroy_mutex(&data->print_mutex);
	destroy_mutex(&data->table_mutex);
	destroy_mutex(&data->death_mutex);
	free(data->forks);
	free(philos);
	free(data);
	exit(1);
}

/* Destroys all the data if there was an error when init */
void	destroy_data(char *error, t_data *data)
{
	int	i;

	i = -1;
	if (ft_strlen(error) != 0)
		printf(ADMIN"Error: %s\n"RESET, error);
	while (++i < data->n_philo)
		destroy_mutex(&data->forks[i]);
	destroy_mutex(&data->print_mutex);
	destroy_mutex(&data->table_mutex);
	destroy_mutex(&data->death_mutex);
	free(data->forks);
	exit(1);
}
