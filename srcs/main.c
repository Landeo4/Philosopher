/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:18:46 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/18 16:12:30 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

int	main(int argc, char *argv[])
{
	t_data		ptr;
	t_philo		philo;
	int			i;

	i = 0;
	if (parsing_manager(argc, argv) == -1)
		return (printf("les test sont pas bon\n"), 0);
	init_data_struct(argv, &ptr);
	init_philo_struct(&philo, &ptr);
	fill_struct(&ptr, &philo);
	create_philo(&ptr, &philo);
	while (i < ptr.nb_philo)
	{
		pthread_mutex_destroy(&ptr.fork[i]);
		i++;
	}
	// pthread_mutex_unlock(ptr.fork[1]);
	// routine(argv, &philo, &ptr);
}

void	create_philo(t_data *ptr, t_philo *philo)
{
	while (philo)
	{
		pthread_create(philo->philo, NULL, &fake_routine, ptr);
		philo = philo->next;
	}
	
}

void	*fake_routine(void *ptr)
{
	t_data		*data;
	t_philo		*philo;

	philo = (t_philo*)ptr;
	data = philo->data_struct;
	printf("je rentre bien dans fake routine\n");
	if (pthread_mutex_lock(&(data->fork[1])) == 0)
		printf("un seul pourra ecrire et c'est %d\n", philo->id);
	else
		printf("ca a rater %d\n", philo->id);
	return (NULL);
}

// void	*fake_routine(void *ptr)
// {
// 	t_data	*data;
// 	t_philo	*philo;

// 	philo = (t_philo*)ptr;
// 	data = philo->data_struct;
// 	(void)data;
// 	while (philo->philo)
// 	{
// 		printf("salut je suis %d\n", philo->id);
// 		philo = philo->next;
// 	}
// 	return (NULL);
// }

// void	routine(char *argv[], t_struct *ptr, t_data *data)
// {
// 	(void)ptr;
// 	(void)argv;
// 	eat(ptr, data);
// }

// void	*routine()
// {
// 	t_struct *phil;
// 	pthread_mutex_t mutex;

// 	pthread_mutex_init(&mutex, NULL);
// 	if (pthread_create(phil->philo, NULL, &routine, NULL) != 0)
// 		return (1);
// 	if (pthread_create(phil->philo->next, NULL, &routine, NULL) != 0)
// 		return 2;
// 	if (pthread_join(t1, NULL) == -1)
// 		return 3;
// 	if (pthread_join(t2, NULL) == -1)
// 		return 4;
// 	pthread_mutex_destroy(&mutex);
// 	return (0);
// }

// int mail = 0;

// void	*routine(pthread_mutex_t *mutex)
// {
// 	int i = 0;
// 	while (i < 100)
// 	{
// 		pthread_mutex_lock(mutex);

// 		pthread_mutex_unlock(mutex);
// 		mail++;
// 		i++;
// 	}
// 	return NULL;
// }

// int main(int argc, char *argv[])
// {
// 	(void)argc;
// 	(void)argv;
// 	pthread_mutex_t mutex;
// 	pthread_t t1, t2;
// 	pthread_mutex_init(&mutex, NULL);
// 	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
// 		return (1);
// 	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
// 		return 2;
// 	if (pthread_join(t1, NULL) == -1)
// 		return 3;
// 	if (pthread_join(t2, NULL) == -1)
// 		return 4;
// 	pthread_mutex_destroy(&mutex);
// 	printf("Number of mails %d\n", mail);
// 	return (0);
// }
