/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:19:31 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/17 16:46:57 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdint.h>

/*
================================
			Structure
================================
*/

typedef struct s_philo
{
	int				id;
	pthread_t		philo;
	struct s_philo	*next;
	struct s_data	*data_struct;
}		t_philo;


typedef struct s_data
{
	pthread_mutex_t	*fork;
	int	nb_philo;
	int	eat_time;
	int	sleep_time;
	int	die_time;
	int	nb_eat;
	pthread_mutex_t	*mutex;
	t_philo			*ph_struct;
}		t_data;

/*
================================
			Philo
================================
*/

int		main(int argc, char *argv[]);
void	philo_main(char *argv[], t_data *ptr);
void	*fake_routine(void *ptr);

/*
================================
			Parsing
================================
*/

int		parsing_manager(int argc, char *argv[]);

/*
================================
			Utils
================================
*/

int		ft_strlen(char *str);
int		verif_numbers(char *argv[]);
int		verif_overflow(char *argv[]);
int		verif_overflow_max(char *argv[], char *max);
int		ft_isdigit(int c);
int		is_num_only(char *argv[]);
void	philo_eat(int time, int id);
void	philo_fork(int time, int id);
void	philo_sleep(int time, int id);
void	philo_think(int time, int id);
void	philo_died(int time, int id);
void	init_data_struct(char *argv[], t_data *ptr);
t_philo *init_philo_struct(t_philo *ptr, t_data *data);
int		ft_atoi(const char *nptr);
void	ft_free_philo(t_philo *ptr);
void	*ft_calloc(size_t nmemb, size_t size);
t_philo	*ft_createcell_philo();
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
t_philo	*ft_add_at(t_philo *L, int pos);
void	fill_struct(t_data *dat, t_philo *ptr1);
void	routine(char *argv[], t_philo *ptr, t_data *data);
t_data	*create_fork(t_data *data);

#endif