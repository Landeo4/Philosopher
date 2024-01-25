/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:47:12 by tpotilli          #+#    #+#             */
/*   Updated: 2024/01/25 20:49:01 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

int	one_philo_solution(t_data *ptr)
{
	ptr->beginning = ft_get_time();
	if (pthread_create(&ptr->thre_id[0], NULL, &one_philo_solver, &ptr->philos[0]))
		return (error_and_free("Thread error.", ptr));
	if (pthread_join(ptr->thre_id[0], NULL))
		return (error_and_free("Detach error.", ptr));
	free_struct(ptr);
	return (0);
}

void	*one_philo_solver(void *philo_ptr)
{
	t_philo	*philo;
	int		death_timer;
	int		actual_time;

	philo = (t_philo *) philo_ptr;
	death_timer = philo->data->death_time;
	actual_time = ft_get_time();
	philo->time_to_die = death_timer + actual_time;
	event_log("has taken a fork", philo);
	ft_usleep(philo->data->death_time);
	event_log("died", philo);
	return (NULL);
}

void	*monitor(void *data_ptr)
{
	t_philo	*philo;
	int		ended;

	philo = (t_philo *) data_ptr;
	pthread_mutex_lock(&philo->data->lock);
	ended = philo->data->is_dead;
	pthread_mutex_unlock(&philo->data->lock);
	while (!ended)
	{
		pthread_mutex_lock(&philo->data->lock);
		ended = philo->data->is_dead;
		pthread_mutex_unlock(&philo->data->lock);
		pthread_mutex_lock(&philo->data->lock);
		if (philo->data->finished >= philo->data->n_philo)
			philo->data->is_dead = 1;
		pthread_mutex_unlock(&philo->data->lock);
	}
	return (NULL);
}

void	*routine(void *philo_pointer)
{
	t_philo	*philo;
	int		is_alive;

	philo = (t_philo *) philo_pointer;
	pthread_mutex_lock(&philo->data->lock);
	is_alive = philo->data->is_dead;
	pthread_mutex_unlock(&philo->data->lock);
	philo->time_to_die = philo->data->death_time + ft_get_time();
	if (pthread_create(&philo->t1, NULL, &supervisor, (void *)philo)) // verif avant en cas ou fail puis free
		return (NULL); // donc vois si la simu n'a pas fail
	if (pthread_detach(philo->t1))
		return (NULL);
	while (is_alive == 0)
	{
		pthread_mutex_lock(&philo->data->lock);
		is_alive = philo->data->is_dead;
		pthread_mutex_unlock(&philo->data->lock);
		eat(philo);
		event_log("is thinking", philo);
	}
	return (NULL);
}

void	*supervisor(void *philo_pointer)
{
	t_philo	*philo;
	int		is_alive;

	philo = (t_philo *) philo_pointer;
	pthread_mutex_lock(&philo->data->lock);
	is_alive = philo->data->is_dead;
	pthread_mutex_unlock(&philo->data->lock);
	while (is_alive == 0)
	{
		pthread_mutex_lock(&philo->data->lock);
		is_alive = philo->data->is_dead;
		pthread_mutex_unlock(&philo->data->lock);
		pthread_mutex_lock(&philo->lock);
		if (ft_get_time() >= philo->time_to_die && philo->is_eating == 0)
			event_log("died", philo);
		if (philo->eat_count == philo->data->n_eat)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->finished++;
			philo->eat_count++;
			pthread_mutex_unlock(&philo->data->lock);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return (NULL);
}
