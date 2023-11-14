/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_overflow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:14:04 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/14 14:52:26 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

int	verif_numbers(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
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
	char	*max;

	max = "2147483647";
	if (verif_overflow_max(argv, max) == -1)
		return (-1);
	return (0);
}

// int	verif_overflow_min(char *argv[], int min, len)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (argv[i] )
// }

int	verif_overflow_max(char *argv[], char *max)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (argv[i])
	{
		len = ft_strlen(argv[i]);
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] > max[j] && len > 9)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
