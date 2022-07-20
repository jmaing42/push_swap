/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_rotate_up.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:09:11 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/21 00:12:04 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include "ft_primitive_size_t.h"
#include "ps_stream.h"

t_err	ps_solve_util_rotate_up(
	t_ps_stream *stream,
	size_t left,
	size_t right,
	bool from_right
)
{
	const size_t	rr = ft_primitive_size_t_min(left, right);
	const size_t	ra = left - rr;
	const size_t	rb = right - rr;
	size_t			i;

	i = -1;
	while (++i < rr)
		if (ps_stream_append_rr(stream, rr))
			return (true);
	i = -1;
	while (++i < ra)
		if (ps_stream_append_ra(stream, ra, from_right))
			return (true);
	i = -1;
	while (++i < rb)
		if (ps_stream_append_rb(stream, rb, from_right))
			return (true);
	return (false);
}
