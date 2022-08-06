/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_rotate_down.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:12:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/06 23:03:47 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include "ft_types_primitive_size_t.h"
#include "ps_stream.h"

t_err	ps_solve_util_rotate_down(
	const t_ps_solve_context *context,
	const t_ps_solve_util_array *left,
	const t_ps_solve_util_array *right,
	bool from_right
)
{
	const size_t	rrr = ft_types_primitive_size_t_min(left->length, right->length);
	const size_t	rra = left->length - rrr;
	const size_t	rrb = right->length - rrr;
	size_t			i;

	i = -1;
	while (++i < rrr)
		if (ps_stream_append_rrr(context->stream, rrr))
			return (true);
	i = -1;
	while (++i < rra)
		if (ps_stream_append_rra(context->stream, rra, from_right))
			return (true);
	i = -1;
	while (++i < rrb)
		if (ps_stream_append_rrb(context->stream, rrb, from_right))
			return (true);
	return (false);
}
