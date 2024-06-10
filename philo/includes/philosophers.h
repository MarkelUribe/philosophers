/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:33:34 by muribe-l          #+#    #+#             */
/*   Updated: 2024/06/10 19:08:49 by muribe-l         ###   ########.fr       */
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
	int				n_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			times_philo_must_eat;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	dead_mutex;
}	t_data;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	fork;
	int				id;
	int				eating;
	int				sleeping;
	int				thinking;
	int				dead;
	t_data			*data;
}	t_philo;

int				parse(int argc, char **argv);
int				ft_atoi(const char *str);
int				ft_strlen(char *str);
void			init_data(int argc, char **argv, t_data *data);
void			init_philos(t_philo *philos, t_data *data);
void			destroy_all(char *error, t_philo *philos, t_data *data);
void			routine(t_philo *philo);
void			init_threads(t_philo *philos, t_data *data);
void		print_message(char *str, t_philo *philo, int id);

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