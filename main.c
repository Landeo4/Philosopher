/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:18:46 by tpotilli          #+#    #+#             */
/*   Updated: 2024/01/25 18:35:08 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

int	init_master(t_data *ptr, char **argv)
{
	init_struct(ptr, argv);
	if (init_pointers(ptr))
		return (0);
	init_forks(ptr);
	init_philos(ptr);
	if (ptr->n_philo == 1)
		return (one_philo_solution(ptr));
	if (init_threads(ptr))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data			*ptr;

	if (argc < 5 || argc > 6)
		return (pr_error("Not enough arguments."));
	if (!verify_arguments(argv, argc))
		return (0);
	ptr = malloc(sizeof(t_data));
	if (!ptr)
		return (0);
	if (!init_master(ptr, argv))
		return (0);
	free_struct(ptr);
	return (1);
}
