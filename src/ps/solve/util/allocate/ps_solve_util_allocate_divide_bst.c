/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_allocate_divide_bst.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 23:13:09 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/06 23:20:51 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include "ft_types_primitive_pointer.h"

t_ps_solve_util_parts	*ps_solve_util_allocate_divide_bst(
	const int *array,
	t_ps_solve_count_size size
)
{
	t_ps_solve_util_parts *const	result
		= ps_solve_util_allocate_divide(array, size);

	if (!result)
		return (NULL);
	ft_types_primitive_pointer_swap((void *)&result->a, (void *)&result->c);
	ft_types_primitive_pointer_swap((void *)&result->x, (void *)&result->z);
	return (result);
}
