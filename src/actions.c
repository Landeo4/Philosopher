/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:56:08 by tpotilli          #+#    #+#             */
/*   Updated: 2024/01/25 15:45:22 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

void	event_log(char *str, t_philo *philo)
{
	u_int64_t	time;

	pthread_mutex_lock(&philo->data->write);
	time = ft_get_time() - philo->data->start_time;
	if (ft_strcmp("died", str) == 0 && !philo->data->dead)
	{
		printf("\e[1;34m%lu\t\e[0m\t\e[1;35m%d\e[0m\t\e[1;32m%s\e[0m\n",
			time, philo->id, str);
		pthread_mutex_lock(&philo->data->lock);
		philo->data->dead = 1;
		pthread_mutex_unlock(&philo->data->lock);
	}
	pthread_mutex_lock(&philo->data->lock);
	if (!philo->data->dead)
		printf("\e[1;34m%lu\t\e[0m\t\e[1;35m%d\e[0m\t\e[1;32m%s\e[0m\n",
			time, philo->id, str);
	pthread_mutex_unlock(&philo->data->lock);
	pthread_mutex_unlock(&philo->data->write);
}

/*
! ---------------------------------------------------------------------------
*							- EAT -
! ---------------------------------------------------------------------------

? This function works as follows :
* - Will take the forks.
* - Will update the death timers, eat count, print the event msg.
* - Will drop the forks...

*/

void	eat(t_philo *philo)
{
	if (philo->id % 2 != 0)
		take_forks_r_l(philo);
	else
		take_forks_l_r(philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating = 1;
	philo->time_to_die = ft_get_time() + philo->data->death_time;
	event_log("is eating", philo);
	philo->eat_cont++;
	ft_usleep(philo->data->eat_time);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->lock);
	if (philo->id % 2 != 0)
		drop_forks_l_r(philo);
	else
		drop_forks_r_l(philo);
}
