/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:52:43 by tpotilli          #+#    #+#             */
/*   Updated: 2024/01/26 11:58:00 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

int	init_threads(t_data *ptr)
{
	int			i;
	pthread_t	t0;

	i = 0;
	ptr->beginning = ft_get_time();
	if (ptr->n_eat > 0)
	{
		if (pthread_create(&t0, NULL, &monitor, &ptr->philos[0]))
			return (error_and_free("Error when creating a thread", ptr));
		if (pthread_detach(t0))
			return (error_and_free("Detach error.", ptr));
	}
	while (i < ptr->n_philo)
	{
		if (pthread_create(&ptr->t_id[i], NULL, &routine, &ptr->philos[i]))
			return (error_and_free("Error when creating a thread", ptr));
		ft_usleep(1);
		i++;
	}
	return (0);
}

int	thread_collector(t_data *ptr)
{
	int	i;

	i = 0;
	while (i < ptr->n_philo)
	{
		if (pthread_join(ptr->t_id[i], NULL))
			return (error_and_free("Thread join error.", ptr));
		i++;
	}
	return (0);
}
