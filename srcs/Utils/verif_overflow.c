/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_overflow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:14:04 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/14 13:56:35 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

int	verif_overflow(int argc, char *argv[])
{
	int		len;
	char	*max;
	char	*min;
	(void)argc;

	len = 10;
	max = "2147483647";
	min = "-2147483648";
	// if (verif_overflow_min(argv, min, len) == -1)
	// 	return (-1);
	if (verif_overflow_max(argv, max, len) == -1)
		return (-1);
	// while (argv[i])
	// {
	// 	if (ft_strlen(argv[i]) > len)
	// 		return (-1);
	// 	j = 0;
	// 	while (argv[i][j])
	// 	{
			
	// 		j++;
	// 	}
	// 	i++;
	// }
	return (0);
}

// int	verif_overflow_min(char *argv[], int min, len)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (argv[i] )
// }

int	verif_overflow_max(char *argv[], int max, int len)
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
			if (argv[i][j] > max[j] && len > 10)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
