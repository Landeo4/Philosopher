/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_overflow_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:29:51 by tpotilli          #+#    #+#             */
/*   Updated: 2024/01/26 13:53:44 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

int	int_overflow_checker(char *str)
{
	if (ft_strlen(str) > 11)
		return (pr_error("Integer overflow/underflow detected."));
	else if (integer_checker(str) != 1)
		return (0);
	return (1);
}

int	integer_checker(char *str)
{
	long	n;

	n = ft_atol(str);
	if (n > INT_MAX)
		return (pr_error("Integer overflow detected."));
	else if (n < INT_MIN)
		return (pr_error("Integer underflow detected."));
	return (1);
}
