/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:46:20 by tpotilli          #+#    #+#             */
/*   Updated: 2024/01/25 17:43:02 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

void	take_forks_r_l(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	event_log("has taken a fork", philo);
	pthread_mutex_lock(philo->l_fork);
	event_log("has taken a fork", philo);
}

void	take_forks_l_r(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	event_log("has taken a fork", philo);
	pthread_mutex_lock(philo->r_fork);
	event_log("has taken a fork", philo);
}

void	drop_forks_l_r(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	event_log("is sleeping", philo);
	ft_usleep(philo->data->sleep_time);
}

void	drop_forks_r_l(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	event_log("is sleeping", philo);
	ft_usleep(philo->data->sleep_time);
}
