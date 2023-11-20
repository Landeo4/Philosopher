/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:19:31 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/20 13:44:45 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdint.h>
# include <time.h>
# include <sys/types.h>
# include <stdint.h>

/*
================================
			Structure
================================
*/

typedef struct s_philo
{
	int				id;
	int				has_eaten;
	pthread_t		philo;
	struct s_philo	*next;
	struct s_data	*data_struct;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}		t_philo;

typedef struct s_data
{
	pthread_mutex_t	*fork;
	int				nb_philo;
	u_int64_t		eat_time;
	u_int64_t		sleep_time;
	u_int64_t		die_time;
	u_int64_t		think_time;
	u_int64_t		real_time;
	int				nb_eat;
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
int		create_philo(t_data *ptr, t_philo *philo);
void	philo_eat(t_philo *ptr, t_data *data);
void	philo_sleep(t_data *data);
void	philo_think(t_data *data);

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
void	philo_eat_show(u_int64_t time, int id);
void	philo_fork_show(u_int64_t time, int id);
void	philo_sleep_show(u_int64_t time, int id);
void	philo_think_show(u_int64_t time, int id);
void	philo_died_show(u_int64_t time, int id);
t_data	*init_data_struct(char *argv[], t_data *ptr);
t_philo	*init_philo_struct(t_data *data);
int		ft_atoi(const char *nptr);
void	ft_free_philo(t_philo *ptr);
void	*ft_calloc(size_t nmemb, size_t size);
t_philo	*ft_createcell_philo(int num);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
t_philo	*ft_add_at(t_philo *L, int nb, int pos);
int		fill_struct(t_data *dat, t_philo *ptr1);
t_data	*create_fork(t_data *data);
int		init_all_struct(t_data *ptr, t_philo *philo, char *argv[]);

#endif