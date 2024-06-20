/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:09:32 by muribe-l          #+#    #+#             */
/*   Updated: 2024/06/20 13:26:39 by muribe-l         ###   ########.fr       */
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

static int	ft_isdigit(int c)
{
	return ((c > 47 && c < 58));
}

static int	ft_string_of_digits(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/* checks that all the arguments are numbers */
static int	args_are_number(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (!ft_string_of_digits(argv[i]))
		{
			printf(ADMIN"Error: Invalid number of arguments\n"RESET);
			printarguments();
			return (0);
		}
		if (i == 5)
		{
			if (ft_atoi(argv[5]) <= 0)
			{
				printf(ADMIN"Error: args must be bigger than 0\n"RESET);
				printarguments();
				return (0);
			}
		}
	}
	return (1);
}

/* Checks that all the parameters are correct */
int	parse(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf(ADMIN"Error: Invalid number of arguments\n"RESET);
		printarguments();
		return (0);
	}
	if (!args_are_number(argc, argv))
		return (0);
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
