/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:07:42 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/20 13:57:17 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

int		init_all_struct(t_data *ptr, t_philo *philo, char *argv[])
{
	(void)philo;
	ptr = init_data_struct(argv, ptr);
	// if (!ptr)
	// 	return (-1);
	philo = init_philo_struct(ptr);
	// if (!philo)
	// 	return (-1);
	return (0);
}

t_data	*init_data_struct(char *argv[], t_data *ptr)
{
	ptr->nb_philo = ft_atoi(argv[1]);
	ptr->die_time = ft_atoi(argv[2]);
	ptr->eat_time = ft_atoi(argv[3]);
	ptr->sleep_time = ft_atoi(argv[4]);
	if (argv[5])
		ptr->nb_eat = ft_atoi(argv[5]);
	ptr = create_fork(ptr);
	// if (!ptr->nb_philo || !ptr->sleep_time
	// 	|| !ptr->eat_time || !ptr->die_time)
	// 	return (NULL);
	return (ptr);
}

t_philo	*init_philo_struct(t_data *data)
{
	t_philo *ptr;
	t_philo *new_philo;
	int		i;

	i = 0;
	ptr = NULL;
	printf("debut d'initialisation\n");
	while (i < data->nb_philo)
	{
		new_philo = (t_philo *)malloc(sizeof(t_philo));
		if (!new_philo)
			return (NULL);
		new_philo->id = i;
		new_philo->has_eaten = 0;
		new_philo->next = NULL;
		new_philo->data_struct = data;
		new_philo->r_fork = &(data->fork[i]);
		new_philo->l_fork = &(data->fork[(i - 1)]);
		i++;
	}
	data->ph_struct = ptr;
	printf("fin d'initialisation\n");
	return (ptr);
}


int	philo_fill(t_philo *ptr, t_data *data)
{
	int i;
	(void)ptr;
	
	i = 0;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->fork)
		return (-1);
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		if (!data->fork)
		{
			printf("Error\n problem with Mutex\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

t_data	*create_fork(t_data *data)
{
	int	i;

	i = 0;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->fork)
	{
		printf("probleme with your fork\n");
		return (NULL);
	}
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
		{
			printf("Error\n problem with Mutex\n");
			free(data->fork);
			return (NULL);
		}
		i++;
	}
	return (data);
}

// t_data	*init_data_struct(char *argv[], t_data *ptr)
// {
// 	ptr->nb_philo = ft_atoi(argv[1]);
// 	if (!ptr->nb_philo)
// 		return (NULL);
// 	ptr->die_time = ft_atoi(argv[2]);
// 	if (!ptr->die_time)
// 		return (NULL);
// 	ptr->eat_time = ft_atoi(argv[3]);
// 	if (!ptr->eat_time)
// 		return (NULL);
// 	ptr->sleep_time = ft_atoi(argv[4]);
// 	if (!ptr->sleep_time)
// 		return (NULL);
// 	if (argv[5])
// 		ptr->nb_eat = ft_atoi(argv[5]);
// 	ptr = create_fork(ptr);
// 	return (ptr);
// }