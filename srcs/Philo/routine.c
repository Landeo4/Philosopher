/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:54:28 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/20 13:38:36 by tpotilli         ###   ########.fr       */
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
}

void	philo_sleep(t_data *data)
{
	philo_sleep_show(data->real_time, data->ph_struct->id);
	usleep(data->sleep_time);
}

void	philo_think(t_data *data)
{
	philo_think_show(data->real_time, data->ph_struct->id);
	usleep(data->think_time);
}
