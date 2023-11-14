/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:19:45 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/14 12:36:56 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

int	parsing_manager(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
		return (printf("Error\nwrong input\n") ,-1);
	if (argv[1] > 10000 || argv[2] > 10000
		|| argv[3] > 10000)
		return (printf("Error\ntoo much time\n"), -1)
	if (argc == 6)
	{
		if (argv[4] > 10000)
			return (printf("Error\ntoo much time\n"), -1)
	}
		return ()
}

// argument should looks like
// number_of_philosophers (also the numbers of fork)
// time_to_die (in miliseconds)
// time_to_eat (in miliseconds) need two fork
// time_to_sleep (in miliseconds)
// number_of_time_each_philo_must_eat (optionnal) if not specify
// simulation stop when a Philo dies