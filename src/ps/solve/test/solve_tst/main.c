/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 00:05:04 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/08 00:14:22 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_tst.h"

#include <stdlib.h>

#include "ft_strict_atoi.h"

int	main(int argc, char **argv)
{
	const size_t		length = argc - 1;
	t_ps_stream *const	stream = new_ps_stream(length, 0);
	int *const			arr = malloc(sizeof(int) * length);
	t_ps_solve_context	context;
	size_t				i;

	i = -1;
	while (++i < length)
		if (ft_strict_atoi(argv[i + 1], &arr[i]))
			return (EXIT_FAILURE);
	context.table = NULL;
	context.table_size = 0;
	context.stream = stream;
	if (ps_solve_tst(&context, arr, length, false))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
