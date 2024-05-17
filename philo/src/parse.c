/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:09:32 by muribe-l          #+#    #+#             */
/*   Updated: 2024/05/17 14:26:04 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	printarguments()
{
	printf(	MAGENTA"int number_of_philosophers\n"
			ORANGE"int time_to_die\n"
			YELLOW"int time_to_eat\n"
			GREEN"int time_to_sleep\n"
			AQUA"int number_of_times_each_philosopher_must_eat (optinal)\n"RESET);
}

static void init_values(int argc, char **argv, t_philo *philo)
{
	philo->n_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->times_philo_must_eat = ft_atoi(argv[5]);
	else
		philo->times_philo_must_eat = -1;
}

int	parse(int argc, char **argv, t_philo *philo)
{
	if (argc != 5 || argc != 6)
	{
		printf(ADMIN"Error: Invalid number of arguments\n"RESET);
		printarguments();
		return (0);
	}
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > 200)
	{
		printf(ADMIN"Error: number of philosophers must be between 1 and 200\n"RESET);
		printarguments();
		return (0);
	}
	if (ft_atoi(argv[2]))
	{

	}
	init_values(argc, argv, philo);
	return (1);
}
