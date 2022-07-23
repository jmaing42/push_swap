/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_solve_txb.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 06:43:07 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/24 06:49:03 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

t_err	ps_solve_util_solve_txb(
	const t_ps_solve_context *context,
	t_ps_solve_util_array *array,
	bool from_right,
	bool reverse
)
{
	t_err	result;

	if (reverse)
		ps_solve_util_array_inverse(array);
	result = ps_solve_txb(context, array->array, array->length, from_right);
	if (reverse)
		ps_solve_util_array_inverse(array);
	return (result);
}
