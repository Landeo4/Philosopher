/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:07:42 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/15 15:17:46 by tpotilli         ###   ########.fr       */
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
	ptr->fork = create_fork(ptr);
}

t_philo *init_philo_struct(t_struct *ptr)
{
	ptr->philo = ft_calloc(1, sizeof(t_philo));
	if (!ptr->philo)
		return (NULL);
	ptr->philo->next = NULL;
	return (ptr->philo);
}

void	fill_struct(t_data *dat, t_struct *ptr1)
{
	t_data		*data;
	t_struct	*ptr;
	int			i;

	i = 0;
	data = dat;
	ptr = ptr1;
	while (i < data->nb_philo)
	{
		printf("data->nb_philo %d i %d\n", data->nb_philo, i);
		ft_add_at(ptr->philo, 1);
		i++;
	}
}

t_data	*create_fork(t_data *data)
{
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	
	return (data);
}
