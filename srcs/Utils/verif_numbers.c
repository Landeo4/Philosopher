/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:14:04 by tpotilli          #+#    #+#             */
/*   Updated: 2024/01/23 18:42:06 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

int	verif_numbers(char *argv[])
{
	int	i;
	int	j;
	int	len;

	i = 1;
	while (argv[i])
	{
		len = ft_strlen(argv[i]);
		if (len > 10)
			return (printf("big number\n"), -1);
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < 0)
				return (-1);
			j++;
		}
		i++;
	}
	if (verif_overflow(argv) == -1)
		return (-1);
	return (0);
}

int	verif_overflow(char *argv[])
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if (ft_atol(argv[i]) > 2147483647)
			return (-1);
		i++;
	}
	return (0);
}
