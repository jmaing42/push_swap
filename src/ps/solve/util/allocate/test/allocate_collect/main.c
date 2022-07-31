/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:49:06 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 09:20:46 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "ps_solve.h"
#include "ps_solve_internal.h"

#include "ft_memory.h"

static t_err	test(const int *array, size_t a, size_t b, size_t c)
{
	const t_ps_solve_count_size		size = {a, b, c};
	t_ps_solve_util_parts *const	arr
		= ps_solve_util_allocate_collect(array, size);
	size_t							i;

	if (!arr)
		return (true);
	i = -1;
	while (++i < arr->a.length)
		printf(&"%d\0 %d"[!!i * 3], arr->a.array[i]);
	putchar('\n');
	i = -1;
	while (++i < arr->b.length)
		printf(&"%d\0 %d"[!!i * 3], arr->b.array[i]);
	putchar('\n');
	i = -1;
	while (++i < arr->c.length)
		printf(&"%d\0 %d"[!!i * 3], arr->c.array[i]);
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
