/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_allocate_collect.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:00:48 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 09:11:56 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include <stdlib.h>

#include "ft_memory.h"

t_ps_solve_util_parts	*ps_solve_util_allocate_collect(
	const int *array,
	t_ps_solve_count_size size
)
{
	const size_t					length = size.x + size.y + size.z;
	t_ps_solve_util_parts *const	result = malloc(
			sizeof(t_ps_solve_util_parts) + sizeof(int) * (length));

	if (!result)
		return (NULL);
	ft_memcpy(result->memory, array, sizeof(int) * (length));
	result->a = ps_solve_util_array(result->memory, size.x);
	result->b = ps_solve_util_array(result->memory + size.x, size.y);
	result->c = ps_solve_util_array(result->memory + size.x + size.y, size.z);
	result->x = ps_solve_util_array(array, size.x);
	result->y = ps_solve_util_array(array + size.x, size.y);
	result->z = ps_solve_util_array(array + size.x + size.y, size.z);
	result->original = array;
	ps_solve_util_array_sort((t_ps_solve_util_array_mutable *)&result->a);
	ps_solve_util_array_sort((t_ps_solve_util_array_mutable *)&result->b);
	ps_solve_util_array_sort((t_ps_solve_util_array_mutable *)&result->c);
	return (result);
}
