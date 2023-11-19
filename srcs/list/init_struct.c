/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:07:42 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/19 12:16:21 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

void	init_data_struct(char *argv[], t_data *ptr)
{
	ptr->nb_philo = ft_atoi(argv[1]);
	ptr->die_time = ft_atoi(argv[2]);
	ptr->eat_time = ft_atoi(argv[3]);
	ptr->sleep_time = ft_atoi(argv[4]);
	if (argv[5])
		ptr->nb_eat = ft_atoi(argv[5]);
	create_fork(ptr);
}

t_philo *init_philo_struct(t_philo *ptr, t_data *data)
{
	int		i;

	i = 0;
	printf("debut d'initialisation\n");
	while (i < data->nb_philo)
	{
		ptr->philo = malloc(sizeof(pthread_t) * 1);
		if (!ptr->philo)
			return (NULL);
		ptr = ptr->next;
		i++;
	}
	ptr->next = NULL;
	data->ph_struct = ptr;
	printf("fin d'initialisation\n");
	return (ptr);
}

void	philo_fill(t_philo *ptr, t_data *data)
{
	int i;
	(void)ptr;
	
	i = 0;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->fork)
		return ;
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		if (!data->fork)
		{
			printf("Error\n problem with Mutex\n");
			return ;
		}
		i++;
	}
}

void	fill_struct(t_data *dat, t_philo *ptr1)
{
	t_data		*data;
	t_philo		*ptr;
	int			i;

	i = 0;
	data = dat;
	ptr = ptr1;
	while (i < data->nb_philo)
	{
		ft_add_at(ptr, 1);
		i++;
	}
}

void	create_fork(t_data *data)
{
	int	i;

	i = 0;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->fork)
	{
		printf("probleme with your fork\n");
		return ;
	}
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
		{
			printf("Error\n problem with Mutex\n");
			free(data->fork);
			return ;
		}
		i++;
	}
}
