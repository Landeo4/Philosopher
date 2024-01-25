/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:45:36 by tpotilli          #+#    #+#             */
/*   Updated: 2024/01/25 15:46:00 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

int	error_handler(char *str, t_data *ptr)
{
	pr_error(str);
	if (ptr)
		end_prog_and_free(ptr);
	return (1);
}

void	end_prog_and_free(t_data *ptr)
{
	int	i;

	i = -1;
	while (++i < ptr->n_philo)
	{
		pthread_mutex_destroy(&ptr->forks[i]);
		pthread_mutex_destroy(&ptr->philos[i].lock);
	}
	pthread_mutex_destroy(&ptr->write);
	pthread_mutex_destroy(&ptr->lock);
	free_data(ptr);
}

void	free_data(t_data *ptr)
{
	if (ptr->tid)
		free(ptr->tid);
	if (ptr->forks)
		free(ptr->forks);
	if (ptr->philos)
		free(ptr->philos);
	if (ptr)
		free(ptr);
}
