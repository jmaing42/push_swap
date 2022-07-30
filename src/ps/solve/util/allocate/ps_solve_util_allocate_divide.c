/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_allocate_divide.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:19:11 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/30 21:39:49 by Juyeong Maing    ###   ########.fr       */
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
	result->a = ps_solve_util_array(result->memory, small);
	result->b = ps_solve_util_array(result->memory + small, medium);
	result->c = ps_solve_util_array(result->memory + small + medium, big);
	result->x = ps_solve_util_array(array, small);
	result->y = ps_solve_util_array(array + small, medium);
	result->z = ps_solve_util_array(array + small + medium, big);
	result->original = array;
	ps_solve_util_array_sort_as(&result->a, array, length);
	ps_solve_util_array_sort_as(&result->b, array, length);
	ps_solve_util_array_sort_as(&result->c, array, length);
	if (!result)
		return (NULL);
	return (result);
}
