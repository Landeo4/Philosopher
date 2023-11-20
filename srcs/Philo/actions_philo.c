/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:56:08 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/20 10:01:59 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

void	philo_eat_show(u_int64_t time, int id)
{
	printf("%ld %d is eating\n", time, id);
}

void	philo_fork_show(u_int64_t time, int id)
{
	printf("%ld %d has taken a fork\n", time, id);
}

void	philo_sleep_show(u_int64_t time, int id)
{
	printf("%ld %d is sleeping\n", time, id);
}

void	philo_think_show(u_int64_t time, int id)
{
	printf("%ld %d is thinking\n", time, id);
}

void	philo_died_show(u_int64_t time, int id)
{
	printf("%ld %d died\n", time, id);
}
