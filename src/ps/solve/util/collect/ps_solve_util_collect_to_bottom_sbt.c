/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_collect_to_bottom_sbt.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 09:01:52 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/24 09:12:17 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

t_err	ps_solve_util_collect_to_bottom_sbt(
	const t_ps_solve_context *context,
	const t_ps_solve_util_parts *parts,
	bool from_right
)
{
	const t_ps_solve_util_collect	collect = {
		context->stream,
		&parts->a,
		&parts->c,
		&parts->b,
		from_right,
	};

	return (ps_solve_util_collect_to_bottom(&collect));
}
