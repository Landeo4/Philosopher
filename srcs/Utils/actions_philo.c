/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:56:08 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/14 14:58:24 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

void	philo_eat(int time, int id)
{
	printf("%d %d is eating\n", time, id);
}

void	philo_fork(int time, int id)
{
	printf("%d %d has taken a fork\n", time, id);
}

void	philo_sleep(int time, int id)
{
	printf("%d %d is sleeping\n", time, id);
}

void	philo_think(int time, int id)
{
	printf("%d %d is thinking\n", time, id);
}

void	philo_died(int time, int id)
{
	printf("%d %d died\n", time, id);
}
