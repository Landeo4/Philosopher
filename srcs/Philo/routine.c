/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:54:28 by tpotilli          #+#    #+#             */
/*   Updated: 2024/01/24 19:50:13 by tpotilli         ###   ########.fr       */
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

void	*start_routine(void	*data)
{
	int		end_dead;
	t_philo	*philo;

	philo = (t_philo *)data;
	pthread_mutex_lock(&philo->data_struct->mutex);
	end_dead = philo->data_struct->dead;
	pthread_mutex_unlock(&philo->data_struct->mutex);
	if (philo->data_struct->sav_die_time > ft_get_time())
	{
		end_dead = 1;
		return (NULL);
	}
	philo->data_struct->sav_die_time = philo->data_struct->die_time + ft_get_time();
	if (philo->data_struct->nb_eat == 0)
		return (printf("c'est good\n"), NULL);
	if (end_dead == 0)
	{
		philo_eat(philo, philo->data_struct);
		printf("philo %d is thinking\n", philo->id);
		usleep(philo->data_struct->think_time);
		printf("philo %d is sleeping\n", philo->id);
		usleep(philo->data_struct->sleep_time);
	}
	return (NULL);
}

u_int64_t	ft_get_time(void)
{
	struct timeval	value;

	if (gettimeofday(&value, NULL))
		return (printf("gettimeofday() error"), 0);
	return ((value.tv_sec * (u_int64_t)1000) + (value.tv_usec / 1000));
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
	data->die_time = data->sav_die_time + ft_get_time();
}
