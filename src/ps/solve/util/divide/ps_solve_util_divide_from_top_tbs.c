/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_divide_from_top_tbs.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 09:01:52 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/24 09:23:35 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

t_err	ps_solve_util_divide_from_top_tbs(
	const t_ps_solve_context *context,
	const t_ps_solve_util_parts *parts,
	const int *array,
	bool from_right
)
{
	const t_ps_solve_util_divide	divide = {
		context->stream,
		&parts->c,
		&parts->a,
		&parts->b,
		array,
		from_right,
	};

	return (ps_solve_util_divide_from_top(&divide));
}