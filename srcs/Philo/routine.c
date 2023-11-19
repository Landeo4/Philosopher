/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:54:28 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/19 11:43:42 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

/*
Pour les routines:
manger:
il faut pour ca que je verifie si deux fourchettes sont disponibles
puis je les lock avec mutex et mon philosophe mange pendant ce temps la
une fois que le delai est ecouler, il unlock les fourchettes et passe a
une autre activite
*/

void	*eat(t_philo *ptr, t_data *data)
{
	
}
