/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:52:43 by tpotilli          #+#    #+#             */
/*   Updated: 2024/01/25 18:56:56 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

int	thread_collector(t_data *ptr)
{
	int	i;

	i = 0;
	while (++i < ptr->n_philo)
	{
		if (pthread_join(ptr->thre_id[i], NULL))
			return (error_and_free("Thread join error.", ptr));
		i++;
	}
	return (0);
}
