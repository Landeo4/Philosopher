/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_overflow_checker.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:48:49 by tpotilli          #+#    #+#             */
/*   Updated: 2024/01/25 15:48:56 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

int	ft_int_overflow_checker(char *str)
{
	if (ft_strlen(str) > 11)
		return (pr_error("Integer overflow/underflow detected."));
	else if (ft_integer_checker(str) != 1)
		return (0);
	return (1);
}

int	ft_integer_checker(char *str)
{
	long	n;

	n = ft_atol(str);
	if (n > INT_MAX)
		return (pr_error("Integer overflow detected."));
	else if (n < INT_MIN)
		return (pr_error("Integer underflow detected."));
	return (1);
}
