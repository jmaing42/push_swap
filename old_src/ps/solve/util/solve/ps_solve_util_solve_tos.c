/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_solve_tos.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 06:43:07 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 08:51:33 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

t_err	ps_solve_util_solve_tos(
	const t_ps_solve_context *context,
	t_ps_solve_util_array *array,
	bool from_right,
	bool reverse
)
{
	t_err	result;

	if (reverse)
		ps_solve_util_array_inverse((t_ps_solve_util_array_mutable *)array);
	result = ps_solve_tos(context, array->array, array->length, from_right);
	if (reverse)
		ps_solve_util_array_inverse((t_ps_solve_util_array_mutable *)array);
	return (result);
}