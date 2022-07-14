/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_append_rrb.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:43:35 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/14 23:43:36 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

t_err	ps_stream_internal_append_rrb(t_ps_stream *self, size_t count)
{
	if (
		ps_stream_internal_make_last_node_parallel(self)
		|| ps_stream_internal_make_last_parallel_node_reverse_rotate(
			&self->tail->value.parallel->b
		)
	)
		return (true);
	ps_stream_internal_append_no_check_reverse_rotate(
		&self->tail->value.parallel->b,
		count);
	ps_stream_internal_clear_last(self);
	return (false);
}
