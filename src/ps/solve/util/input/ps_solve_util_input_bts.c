/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_input_bts.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 22:03:02 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/30 22:15:49 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

t_ps_solve_util_input	ps_solve_util_input_bts(
	const t_ps_solve_context *context,
	const t_ps_solve_util_parts *parts,
	bool from_right
)
{
	const t_ps_solve_util_input	result = {
		context->stream,
		(t_ps_solve_util_const_array *)&parts->c,
		(t_ps_solve_util_const_array *)&parts->b,
		(t_ps_solve_util_const_array *)&parts->a,
		parts->original,
		from_right,
	};

	return (result);
}
