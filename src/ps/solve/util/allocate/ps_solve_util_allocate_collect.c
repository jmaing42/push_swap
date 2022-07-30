/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_allocate_collect.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:00:48 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/29 09:32:12 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include <stdlib.h>

#include "ft_memory.h"

t_ps_solve_util_parts	*ps_solve_util_allocate_collect(
	const int *array,
	size_t top,
	size_t middle,
	size_t bottom
)
{
	const size_t					length = top + middle + bottom;
	t_ps_solve_util_parts *const	result = malloc(
			sizeof(t_ps_solve_util_parts) + sizeof(int) * (length));

	if (!result)
		return (NULL);
	ft_memcpy(result->memory, array, sizeof(int) * (length));
	result->a.array = result->memory;
	result->b.array = result->memory + top;
	result->c.array = result->memory + top + middle;
	result->a.length = top;
	result->b.length = middle;
	result->c.length = bottom;
	result->x.array = array;
	result->y.array = array + top;
	result->z.array = array + top + middle;
	result->x.length = top;
	result->y.length = middle;
	result->z.length = bottom;
	result->original.array = array;
	result->original.length = length;
	ps_solve_util_array_sort(&result->a);
	ps_solve_util_array_sort(&result->b);
	ps_solve_util_array_sort(&result->c);
	return (result);
}
