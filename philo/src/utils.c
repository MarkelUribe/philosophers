/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:20:42 by muribe-l          #+#    #+#             */
/*   Updated: 2024/06/12 13:55:47 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/* String length */
int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/* Alphanumeric to integer */
int	ft_atoi(const char *str)
{
	int	z;
	int	sign;

	z = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		z *= 10;
		z += *str - '0';
		str++;
	}
	return (z * sign);
}

/* Gets the current time in miliseconds */
size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/* Prints the message with the id of the philo and the current time */
void	print_message(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(&philo->data->print_mutex);
	time = get_time() - philo->data->start_time;
	printf("|%zu| %d %s\n", time, id, str);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

/* Bugless usleep in miliseconds */
void	ft_usleep(int ms)
{
	size_t	start;

	start = get_time();
	while (get_time() < start + ms)
		usleep(1);
}
