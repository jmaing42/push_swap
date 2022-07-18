/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 00:24:14 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/17 01:30:32 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "ps_solve_internal.h"

static size_t	print(
	const t_ps_solve_table *unused,
	size_t x,
	size_t y,
	size_t z
)
{
	(void)unused;
	printf("%zu %zu %zu\n", x, y, z);
	return (0);
}

int	main(int argc, char **argv)
{
	int	count;

	if (argc < 2)
		return (EXIT_FAILURE);
	count = atoi(argv[1]);
	if (count < 0)
		return (EXIT_FAILURE);
	ps_solve_util_try_all_permutation(NULL, print, count);
	return (EXIT_SUCCESS);
}
