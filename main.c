/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:18:46 by tpotilli          #+#    #+#             */
/*   Updated: 2024/01/26 09:39:01 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

int	main(int argc, char **argv)
{
	t_data			*ptr;

	if (argc < 5 || argc > 6)
		return (pr_error("Not enough arguments."));
	if (!verify_arguments(argv, argc))
		return (0);
	ptr = malloc(sizeof(t_data));
	if (!ptr)
		return (0);
	if (!init_all_struct(ptr, argv))
		return (0);
	free_struct(ptr);
	return (1);
}
