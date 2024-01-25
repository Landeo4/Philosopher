/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:48:26 by tpotilli          #+#    #+#             */
/*   Updated: 2024/01/25 15:48:33 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

u_int64_t	ft_get_time(void)
{
	struct timeval	value;

	if (gettimeofday(&value, NULL))
		return (error_handler("gettimeofday() error", NULL));
	return ((value.tv_sec * (u_int64_t)1000) + (value.tv_usec / 1000));
}
