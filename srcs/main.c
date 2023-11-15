/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:18:46 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/15 11:28:44 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

// int	main(int argc, char *argv[])
// {
// 	t_data		ptr;
// 	t_struct	philo;

// 	if (parsing_manager(argc, argv) == -1)
// 		return (printf("les test sont pas bon\n"), 0);
// 	printf("les tests sont bon\n");
// 	init_data_struct(argv, &ptr);
// 	init_philo_struct(&philo);
// 	philo_main(argv, &ptr);
// }

// void	philo_main(char *argv[], t_data *ptr)
// {
// 	(void)ptr;
// 	(void)argv;
	
// }

int mail = 0;

void	*routine(pthread_mutex_t *mutex)
{
	int i = 0;
	while (i < 100)
	{
		pthread_mutex_lock(mutex);

		pthread_mutex_unlock(mutex);
		mail++;
		i++;
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	pthread_mutex_t mutex;
	pthread_t t1, t2;
	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return (1);
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return 2;
	if (pthread_join(t1, NULL) == -1)
		return 3;
	if (pthread_join(t2, NULL) == -1)
		return 4;
	pthread_mutex_destroy(&mutex);
	printf("Number of mails %d\n", mail);
	return (0);
}
