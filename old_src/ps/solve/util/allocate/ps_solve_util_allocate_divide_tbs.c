/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_allocate_divide_tbs.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 23:13:09 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/06 23:19:15 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include "ft_types_primitive_pointer.h"

t_ps_solve_util_parts	*ps_solve_util_allocate_divide_tbs(
	const int *array,
	t_ps_solve_count_size size
)
{
	t_ps_solve_util_parts *const	result
		= ps_solve_util_allocate_divide(array, size);

	if (!result)
		return (NULL);
	ft_types_primitive_pointer_swap((void *)&result->a, (void *)&result->b);
	ft_types_primitive_pointer_swap((void *)&result->x, (void *)&result->y);
	ft_types_primitive_pointer_swap((void *)&result->b, (void *)&result->c);
	ft_types_primitive_pointer_swap((void *)&result->y, (void *)&result->z);
	return (result);
}
