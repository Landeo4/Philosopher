/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:19:31 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/14 13:58:03 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[]);

/*
================================
			Parsing
================================
*/

int	parsing_manager(int argc, char *argv[]);

/*
================================
			Utils
================================
*/

int	ft_strlen(char *str);
int	verif_overflow(int argc, char *argv[]);
int	verif_overflow_max(char *argv[], int max, int len);

#endif