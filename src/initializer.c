/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:46:46 by tpotilli          #+#    #+#             */
/*   Updated: 2024/01/25 19:15:06 by tpotilli         ###   ########.fr       */
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
		if (pthread_create(&ptr->thre_id[i], NULL, &routine, &ptr->philos[i]))
			return (error_and_free("Error when creating a thread", ptr));
		ft_usleep(1);
		i++;
	}
	return (0);
}

void	init_philos(t_data *ptr)
{
	int	i;

	i = 0;
	while (i < ptr->n_philo)
	{
		ptr->philos[i].is_eating = 0;
		ptr->philos[i].eat_count = 0;
		ptr->philos[i].time_to_die = ptr->death_time;
		ptr->philos[i].status = 0;
		ptr->philos[i].id = i + 1;
		ptr->philos[i].data = ptr;
		pthread_mutex_init(&ptr->philos[i].lock, NULL);
		i++;
	}
}

void	init_struct(t_data *ptr, char **argv)
{
	ptr->n_philo = ft_atol(argv[1]);
	ptr->death_time = (u_int16_t) ft_atol(argv[2]);
	ptr->eat_time = (u_int16_t) ft_atol(argv[3]);
	ptr->sleep_time = (u_int16_t) ft_atol(argv[4]);
	ptr->is_dead = 0;
	ptr->finished = 0;
	if (argv[5])
		ptr->n_eat = ft_atol(argv[5]);
	else
		ptr->n_eat = 0;
	pthread_mutex_init(&ptr->lock, NULL);
	pthread_mutex_init(&ptr->write, NULL);
	pthread_mutex_init(&ptr->end, NULL);
}

int	init_pointers(t_data *ptr)
{
	ptr->thre_id = malloc(sizeof(pthread_t) * ptr->n_philo);
	if (!ptr->thre_id)
		return (error_and_free("Allocation error.", ptr));
	ptr->forks = malloc(sizeof(pthread_mutex_t) * ptr->n_philo);
	if (!ptr->forks)
		return (error_and_free("Allocation error.", ptr));
	ptr->philos = malloc(sizeof(t_philo) * ptr->n_philo);
	if (!ptr->philos)
		return (error_and_free("Allocation error.", ptr));
	return (0);
}

void	init_forks(t_data *ptr)
{
	int	i;

	i = 0;
	while (i < ptr->n_philo)
	{
		pthread_mutex_init(&ptr->forks[i], NULL);
		i++;
	}
	i = 0;
	ptr->philos[0].l_fork = &ptr->forks[0];
	ptr->philos[0].r_fork = &ptr->forks[ptr->n_philo - 1];
	i = 1;
	while (i < ptr->n_philo)
	{
		ptr->philos[i].l_fork = &ptr->forks[i];
		ptr->philos[i].r_fork = &ptr->forks[i - 1];
		i++;
	}
}
