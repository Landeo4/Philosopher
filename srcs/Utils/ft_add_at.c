/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:41:15 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/15 11:05:37 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

t_philo	*ft_add_at_a(t_philo *L, int data, int pos, int index)
{
	t_philo	*prec;
	t_philo	*cur;
	t_philo	*cell;
	int			i;

	cur = L;
	prec = L;
	i = 0;
	cell = ft_createcell_philo(data, index, pos);
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
