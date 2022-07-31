/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_input_tbs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 22:03:02 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 08:48:32 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

t_ps_solve_util_input	ps_solve_util_input_tbs(
	const t_ps_solve_context *context,
	const t_ps_solve_util_parts *parts,
	bool from_right
)
{
	const t_ps_solve_util_input	result = {
		context->stream,
		(t_ps_solve_util_array *)&parts->c,
		(t_ps_solve_util_array *)&parts->a,
		(t_ps_solve_util_array *)&parts->b,
		parts->original,
		from_right,
	};

	return (result);
}
