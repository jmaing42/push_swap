/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:49:06 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/23 11:17:02 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "ps_solve_internal.h"

#include "ft_memory.h"

static t_err	test(const int *array, size_t a, size_t b, size_t c)
{
	t_ps_solve_util_parts *const	arr
		= ps_solve_util_allocate_collect(array, a, b, c);
	size_t							i;
	t_ps_stream *const				stream = new_ps_stream(a, b + c);
	const t_ps_solve_util_collect	collect = {
		stream,
		&arr->a,
		&arr->b,
		&arr->c,
		false
	};

	if (!arr || !stream)
		return (true);
	ps_solve_util_array_reverse(&arr->a);
	ps_solve_util_array_reverse(&arr->b);
	if (ps_solve_util_collect_to_bottom(&collect) || ps_stream_print(stream, 1))
		return (true);
	i = -1;
	while (++i < a + b + c)
		printf(&"%d\0 %d"[!!i * 3], arr->memory[i]);
	putchar('\n');
	return (false);
}

int	main(int argc, char **argv)
{
	size_t	a;
	size_t	b;
	size_t	c;
	int		*array;
	size_t	i;

	if (argc > 1)
		freopen(argv[1], "r", stdin);
	if (scanf("%zu %zu %zu", &a, &b, &c) != 3)
		return (EXIT_FAILURE);
	array = malloc((a + b + c) * sizeof(int));
	if (!array)
		return (EXIT_FAILURE);
	i = -1;
	while (++i < a + b + c)
		if (scanf("%d", &array[i]) != 1)
			return (EXIT_FAILURE);
	if (test(array, a, b, c))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
