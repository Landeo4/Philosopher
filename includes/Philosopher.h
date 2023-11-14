/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:19:31 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/14 15:15:33 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include <stdio.h>
#include <unistd.h>

/*
================================
			Structure
================================
*/

typedef struct s_philo
{
	int	nb_fork;
	int	nb_philo;
	int	eat_time;
	int	sleep_time;
	int	die_time;
	int	nb_eat;
}	t_philo;

/*
================================
			Philo
================================
*/

int		main(int argc, char *argv[]);
void	philo_test(char *argv[], t_philo *ptr);

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
void	init_struct(char *argv[], t_philo *ptr);
int		ft_atoi(const char *nptr);

#endif