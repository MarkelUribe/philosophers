/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:33:34 by muribe-l          #+#    #+#             */
/*   Updated: 2024/06/05 14:27:30 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

# define PHILO_MAX	200

# define ADMIN		"\033[31m"
# define ORANGE		"\033[38;5;202m"
# define BROWN		"\033[38;5;130m"
# define YELLOW		"\033[93m"
# define PUKE		"\033[33m"
# define LIME		"\033[92m"
# define GREEN		"\033[32m"
# define AQUA		"\033[96m"
# define SKY		"\033[94m"
# define MAGENTA	"\033[35m"
# define RESET		"\033[0m"

typedef struct s_data
{
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			times_philo_must_eat;
}	t_data;

/*
initialize (&data)
en cada philo:
	philo->data = &data;
*/

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	pthread_mutex_t	fork;
	int				dead;
	t_data			*data;
	t_philo			*next;
}	t_philo;

typedef struct s_program
{
	t_philo			*philos;

}	t_program;

int		parse(int argc, char **argv, t_program *program);
int		ft_atoi(const char *str);
int		ft_strlen(char *str);
void	init_forks(pthread_mutex_t *forks, int n_philo);

#endif

/*

pthread_mutex_lock(philo->&mutex)
if (palmaste)
	f_muerte();
pthread_mutex_lock(philo->next->&mutex)
if (palmaste)
	f_muerte();

 == > DENTRO DE MUTEX LOCK
	if (*mutex = 1)
		*mutex = 0;
	else
		wait();

*/