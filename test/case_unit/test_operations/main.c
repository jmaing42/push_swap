/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:52:12 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/04 11:08:23 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/push_swap_solve_internal.h"

int	main(int argc, char **argv)
{
	char	command[4];
	size_t	a;
	size_t	b;
	char	reverse_direction[6];
	bool	parsed;

	if (argc == 2)
		freopen(argv[1], "r", stdin);
	while (scanf("\n%3[^,],%zd,%zd,%5[^\n]",
			command, &a, &b, reverse_direction) == 4)
	{
		parsed = !strcmp(reverse_direction, "true");
		if ((!parsed && strcmp(reverse_direction, "false")))
			return (EXIT_FAILURE);
		else if (!strcmp(command, "px"))
			push_swap_solve_internal_operation_px(a, b, parsed);
		else if (!strcmp(command, "sx"))
			push_swap_solve_internal_operation_sx(parsed);
		else if (!strcmp(command, "rx"))
			push_swap_solve_internal_operation_rx(a, b, parsed);
		else if (!strcmp(command, "rrx"))
			push_swap_solve_internal_operation_rrx(a, b, parsed);
		else
			return (EXIT_FAILURE);
	}
}
