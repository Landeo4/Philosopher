/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:18:46 by tpotilli          #+#    #+#             */
/*   Updated: 2024/01/23 19:28:39 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

int	main(int argc, char *argv[])
{
	t_data		ptr;
	t_philo		philo;
	// int			i;

	// i = 0;
	if (parsing_manager(argc, argv) == -1)
		return (printf("les test sont pas bon\n"), 0);
	init_all_struct(&ptr, &philo, argv);
	// return (-1);
	// free_struct(&philo);
	printf("Les test sont bon\n");
	// while (i < ptr.nb_philo)
	// {
	// 	pthread_create(&(philo.philo), NULL, &fake_routine, &philo);
	// 	usleep(1);
	// 	i++;
	// }
	// while (i < ptr.nb_philo)
	// {
	// 	pthread_mutex_destroy(&ptr.fork[i]);
	// 	i++;
	// }
	// pthread_mutex_unlock(ptr.fork[1]);
	// routine(argv, &philo, &ptr);
}

// void 	free_struct(t_philo *ptr)
// {
// 	int		i;

// 	i = 0;
// 	while (i < 10)
// 	{
// 		free(ptr);
// 		i++;
// 	}
// }
