/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_cell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:42:20 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/19 12:51:12 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

// t_philo	*ft_add_at(t_philo *L, int nb, int pos)
// {
// 	t_philo	*prec;
// 	t_philo	*cur;
// 	t_philo	*cell;
// 	int			i;

// 	cur = L;
// 	prec = L;
// 	i = 0;
// 	cell = ft_createcell_philo(nb);
// 	if (L == NULL)
// 		return (cell);
// 	if (pos == 0)
// 	{
// 		cell->next = L;
// 		return (cell);
// 	}
// 	while (i < pos)
// 	{
// 		i++;
// 		prec = cur;
// 		cur = cur->next;
// 	}
// 	prec->next = cell;
// 	cell->next = cur;
// 	return (L);
// }

// t_philo	*ft_createcell_philo(int nb)
// {
// 	t_philo	*cell;

// 	cell = malloc(sizeof(t_philo));
// 	if (!cell)
// 		return (NULL);
// 	cell->num = nb;
// 	return (cell);
// }
