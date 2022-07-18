/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_allocate_collect.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:00:48 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/18 22:24:50 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ps_solve_internal.h"

#include <stdlib.h>

t_ps_solve_util_parts	*ps_solve_util_allocate_collect(
	const int *array,
	size_t a,
	size_t b,
	size_t c
)
{
	t_ps_solve_util_parts *const	result
		= malloc(
			sizeof(t_ps_solve_util_parts)
			+ sizeof(int) * (a + b + c));

	if (!result)
		return (NULL);
	ft_memcpy(result->memory, array, sizeof(int) * (a + b + c));
	result->a.array = result->memory;
	result->b.array = result->memory + a;
	result->b.array = result->memory + a + b;
	result->a.length = a;
	result->b.length = b;
	result->c.length = c;
	ps_solve_util_sort(&result->a);
	ps_solve_util_sort(&result->b);
	ps_solve_util_sort(&result->c);
	return (result);
}
