/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:41:15 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/15 13:39:05 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

t_philo	*ft_add_at(t_philo *L, int pos)
{
	t_philo	*prec;
	t_philo	*cur;
	t_philo	*cell;
	int			i;

	cur = L;
	prec = L;
	i = 0;
	cell = ft_createcell_philo();
	if (L == NULL)
		return (cell);
	if (pos == 0)
	{
		cell->next = L;
		return (cell);
	}
	while (i < pos)
	{
		i++;
		prec = cur;
		cur = cur->next;
	}
	prec->next = cell;
	cell->next = cur;
	return (L);
}
