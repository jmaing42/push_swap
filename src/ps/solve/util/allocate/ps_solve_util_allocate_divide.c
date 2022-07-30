/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_allocate_divide.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:19:11 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/29 09:32:08 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include <stdlib.h>

#include "ft_memory.h"

t_ps_solve_util_parts	*ps_solve_util_allocate_divide(
	const int *array,
	size_t small,
	size_t medium,
	size_t big
)
{
	const size_t					length = small + medium + big;
	t_ps_solve_util_parts *const	result = malloc(
			sizeof(t_ps_solve_util_parts) + sizeof(int) * (length));

	if (!result)
		return (NULL);
	ft_memcpy(result->memory, array, sizeof(int) * (length));
	ps_solve_util_sort(result->memory, length);
	result->a.array = result->memory;
	result->b.array = result->memory + small;
	result->c.array = result->memory + small + medium;
	result->a.length = small;
	result->b.length = medium;
	result->c.length = big;
	result->x.array = array;
	result->y.array = array + top;
	result->z.array = array + top + middle;
	result->x.length = top;
	result->y.length = middle;
	result->z.length = bottom;
	result->original.array = array;
	result->original.length = length;
	ps_solve_util_array_sort_as(&result->a, array, length);
	ps_solve_util_array_sort_as(&result->b, array, length);
	ps_solve_util_array_sort_as(&result->c, array, length);
	if (!result)
		return (NULL);
	return (result);
}
