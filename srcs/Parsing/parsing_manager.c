/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:19:45 by tpotilli          #+#    #+#             */
/*   Updated: 2024/01/23 19:15:32 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

int	parsing_manager(int argc, char *argv[])
{
	int		i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (printf("Error\nWrong number of arguments\n") ,-1);
	if (is_num_only(argv) == -1)
		return (printf("Error\nplease put valid numbers\n"), -1);
	if (verif_numbers(argv) == -1)
		return (printf("Error\nNumber is too big\n"), -1);
	if (ft_atoi(argv[1]) > 200)
		return (printf("Error\ntoo many Philo put less than 200\n"), -1);
	while (argv[i])
	{
		if (ft_atoi(argv[i]) < 1)
			return (printf("Error\nput a number bigger than 0\n"), -1);
		i++;
	}
	return (0);
}

// argument should looks like
// number_of_philosophers (also the numbers of fork)
// time_to_die (in miliseconds)
// time_to_eat (in miliseconds) need two fork
// time_to_sleep (in miliseconds)
// number_of_time_each_philo_must_eat (optionnal) if not specify
// simulation stop when a Philo dies