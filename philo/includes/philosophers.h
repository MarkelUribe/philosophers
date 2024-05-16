/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:33:34 by muribe-l          #+#    #+#             */
/*   Updated: 2024/05/16 17:04:20 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

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

typedef struct t_philo
{
	int n_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int times_philo_must_eat;
}	t_philo;

int	parse(int argc, char **argv, t_philo *philo);
int	ft_atoi(const char *str);

#endif