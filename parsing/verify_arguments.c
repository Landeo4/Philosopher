/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:55:51 by tpotilli          #+#    #+#             */
/*   Updated: 2024/01/26 09:29:17 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

int	verify_arguments(char **argv, int argc)
{
	if (!overflow_check(argv, argc))
		return (0);
	else if (ft_atol(argv[1]) < 1 || ft_atol(argv[1]) > 200)
		return (pr_error("Invalid amount of philosophers."));
	else if (ft_atol(argv[2]) <= 0 || ft_atol(argv[3]) <= 0
		|| ft_atol(argv[4]) <= 0 || (argv[5] && ft_atol(argv[5]) <= 0))
		return (pr_error("Invalid value detected."));
	return (1);
}

int	overflow_check(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!int_overflow_checker(argv[i]))
			return (0);
		else
			i++;
	}
	return (1);
}
