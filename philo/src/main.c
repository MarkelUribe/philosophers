/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:32:55 by muribe-l          #+#    #+#             */
/*   Updated: 2024/06/05 14:26:27 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_philo			philos;
	pthread_mutex_t	forks[PHILO_MAX];
	t_program		program;

	philos = NULL;

	initialize_philos(&philos);
	if (*philos == NULL)
		*philos = new_node;
	else
		ft_lst_addback(new_node);
	if (!parse(argc, argv, &program))
		return (1);
	program.philos = philos;
	init_forks(forks, argv[1]);
	return (0);
}

/*
void	*bobi(void *bebi)
{
	while (1)
	{
		sleep(1);
		printf("bibibib%s\n", (char *)bebi);
	}
	
	return (NULL);
}

	pthread_t	tid;
	pthread_create(&tid, NULL, bobi, argv[argc - 1]);
	pthread_join(tid, NULL);
*/
