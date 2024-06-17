/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:32:55 by muribe-l          #+#    #+#             */
/*   Updated: 2024/06/12 15:40:26 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	*philos;
	t_data	data;

	philos = NULL;
	if (!parse(argc, argv))
		return (1);
	init_data(argc, argv, &data, philos);
	init_philos(&philos, &data);
	init_threads(philos, &data);
	destroy_all(NULL, philos, &data);
	return (0);
}
