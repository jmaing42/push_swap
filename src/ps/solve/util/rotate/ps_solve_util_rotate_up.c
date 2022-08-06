/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_rotate_up.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:09:11 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/06 23:03:47 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include "ft_types_primitive_size_t.h"
#include "ps_stream.h"

t_err	ps_solve_util_rotate_up(
	const t_ps_solve_context *context,
	const t_ps_solve_util_array *left,
	const t_ps_solve_util_array *right,
	bool from_right
)
{
	const size_t	rr = ft_types_primitive_size_t_min(left->length, right->length);
	const size_t	ra = left->length - rr;
	const size_t	rb = right->length - rr;
	size_t			i;

	i = -1;
	while (++i < rr)
		if (ps_stream_append_rr(context->stream, rr))
			return (true);
	i = -1;
	while (++i < ra)
		if (ps_stream_append_ra(context->stream, ra, from_right))
			return (true);
	i = -1;
	while (++i < rb)
		if (ps_stream_append_rb(context->stream, rb, from_right))
			return (true);
	return (false);
}
