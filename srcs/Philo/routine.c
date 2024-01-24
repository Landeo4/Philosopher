/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:54:28 by tpotilli          #+#    #+#             */
/*   Updated: 2024/01/24 15:16:33 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

/*
Pour les routines:
manger:
il faut pour ca que je verifie si deux fourchettes sont disponibles
puis je les lock avec mutex et mon philosophe mange pendant ce temps la
une fois que le delai est ecouler, il unlock les fourchettes et passe a
une autre activite
*/

int	start_routine(t_data *data, t_philo *philo)
{
	int	end_dead;

	pthread_mutex_lock(end_dead);
	end_dead = 0;
	pthread_mutex_unlock(end_dead);
	if (is_philo_dead(data, philo, data->sav_die_time) == -1)
		return (-1);
	philo_eat(philo, data);
	if (data->nb_eat == 0)
		return (printf("c'est good\n"), 0);
	printf("philo %d is thinking\n", philo->id);
	usleep(data->think_time);
	printf("philo %d is sleeping\n", philo->id);
	usleep(data->sleep_time);
}

int	is_philo_dead(t_data *data, t_philo *philo, int	actual)
{
	int		tmp;
	
	tmp = gettimeofday() + data->die_time;
	if (tmp > actual)
		return (printf("A philo died\n"), -1);
	return (0);
}

void	philo_eat(t_philo *ptr, t_data *data)
{
	printf("%d\n", data->nb_philo);
	if (&(data->fork[ptr->id]) == 0
		&& &(data->fork[(ptr->id - 1)]) == 0)
	{
		pthread_mutex_lock(&(data->fork[ptr->id]));
		pthread_mutex_lock(&(data->fork[ptr->id - 1]));
		philo_eat_show(data->real_time, ptr->id);
		usleep(data->eat_time);
		pthread_mutex_unlock(&(data->fork[ptr->id - 1]));
		pthread_mutex_unlock(&(data->fork[ptr->id]));
	}
	ptr->nb_eat--;
	data->die_time = data->sav_die_time + gettimeofday();
}
