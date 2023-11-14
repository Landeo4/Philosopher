/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:19:45 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/14 13:16:29 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

int	parsing_manager(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
		return (printf("Error\nWrong number of arguments\n") ,-1);
	if (verif_overflow(argc, argv) == -1)
		return (printf("Error\nNumber is too big"), -1);
	return (0);
}

// argument should looks like
// number_of_philosophers (also the numbers of fork)
// time_to_die (in miliseconds)
// time_to_eat (in miliseconds) need two fork
// time_to_sleep (in miliseconds)
// number_of_time_each_philo_must_eat (optionnal) if not specify
// simulation stop when a Philo dies