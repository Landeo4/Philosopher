/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_cell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:42:20 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/15 11:02:30 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

t_philo	*ft_createcell_philo()
{
	t_philo	*cell;

	cell = malloc(sizeof(t_philo));
	if (!cell)
		return (NULL);
	return (cell);
}
