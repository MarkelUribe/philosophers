/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:09:32 by muribe-l          #+#    #+#             */
/*   Updated: 2024/06/12 13:31:12 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/* Prints the formated text that shows the order the arguments must follow. */
static void	printarguments(void)
{
	printf(MAGENTA"int number_of_philosophers\n"
		ORANGE"int time_to_die\n"
		YELLOW"int time_to_eat\n"
		GREEN"int time_to_sleep\n"
		AQUA"int number_of_times_each_philosopher_must_eat (optinal)\n"RESET);
}

/* Checks that all the parameters are correct */
int	parse(int argc, char **argv)
{
	if (!(argc >= 2 && argc <= 6))
	{
		printf(ADMIN"Error: Invalid number of arguments\n"RESET);
		printarguments();
		return (0);
	}
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > PHILO_MAX)
	{
		printf(
			ADMIN"Error: number of philosophers must be between 1 and 200\n"
			RESET);
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
