/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:32:55 by muribe-l          #+#    #+#             */
/*   Updated: 2024/04/30 16:15:29 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*bobi(void *bebi)
{
	while (1)
	{
		sleep(1);
	printf("bibibib%s\n", bebi);
	}
	
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	tid;

	pthread_create(&tid, NULL, bobi, argv[argc - 1]);
	pthread_join(tid, NULL);
}
