/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_rotate_down.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:12:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/21 00:12:50 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include "ft_primitive_size_t.h"
#include "ps_stream.h"

t_err	ps_solve_util_rotate_down(
	t_ps_stream *stream,
	size_t left,
	size_t right,
	bool from_right
)
{
	const size_t	rrr = ft_primitive_size_t_min(left, right);
	const size_t	rra = left - rrr;
	const size_t	rrb = right - rrr;
	size_t			i;

	i = -1;
	while (++i < rrr)
		if (ps_stream_append_rrr(stream, rrr))
			return (true);
	i = -1;
	while (++i < rra)
		if (ps_stream_append_rra(stream, rra, from_right))
			return (true);
	i = -1;
	while (++i < rrb)
		if (ps_stream_append_rrb(stream, rrb, from_right))
			return (true);
	return (false);
}
