/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:09:32 by muribe-l          #+#    #+#             */
/*   Updated: 2024/06/05 16:30:00 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/* 
Prints the formated text that shows the order the arguments must follow.
 */
static void	printarguments()
{
	printf(	MAGENTA"int number_of_philosophers\n"
			ORANGE"int time_to_die\n"
			YELLOW"int time_to_eat\n"
			GREEN"int time_to_sleep\n"
			AQUA"int number_of_times_each_philosopher_must_eat (optinal)\n"RESET);
}

/* Creates, initializes and assigns fork mutex to philo */
static void	add_mutex(t_philo *philo)
{
	pthread_mutex_t	fork;
	
	pthread_mutex_init(&fork, NULL);
	philo->fork = fork;
}

/* Initializes all the philosophers. */
void	init_philos(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		philos[i].id = i + 1;
		philos[i].dead = 0;
		philos[i].data = data;
		add_mutex(&philos[i]);
		i++;
	}
}

/* 
Inserts the parameters into the data structure instance, 
which every philo will point to.
*/
void	init_data(int argc, char **argv, t_data *data)
{
	data->n_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->times_philo_must_eat = ft_atoi(argv[5]);
	else
		data->times_philo_must_eat = -1;
}

/* Checks that all the parameters are correct */
int	parse(int argc, char **argv)
{
	if (argc != 5 || argc != 6)
	{
		printf(ADMIN"Error: Invalid number of arguments\n"RESET);
		printarguments();
		return (0);
	}
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > PHILO_MAX)
	{
		printf(ADMIN"Error: number of philosophers must be between 1 and 200\n"RESET);
		printarguments();
		return (0);
	}
	if (ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0)
	{
		printf(ADMIN"Error: args must be bigger than 0\n"RESET);
		printarguments();
		return (0);
	}
	return (1);
}
