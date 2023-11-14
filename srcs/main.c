/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:18:46 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/14 15:13:07 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

int	main(int argc, char *argv[])
{
	t_philo ptr;

	if (parsing_manager(argc, argv) == -1)
		return (printf("les test sont pas bon\n"), 0);
	printf("les tests sont bon\n");
	philo_test(argv, &ptr);
}

void	philo_test(char *argv[], t_philo *ptr)
{
	init_struct(argv, ptr);
}
