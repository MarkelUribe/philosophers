/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:32:55 by muribe-l          #+#    #+#             */
/*   Updated: 2024/07/17 14:41:17 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include <string.h>

int	main(int argc, char **argv)
{
	t_philo	*philos;
	t_data	*data;

	if (!parse(argc, argv))
		return (1);
	philos = NULL;
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	init_data(argc, argv, data);
	init_philos(&philos, data);
	init_threads(philos, data);
	destroy_all(NULL, philos, data);
	return (0);
}
