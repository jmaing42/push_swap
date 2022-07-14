/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_append_sa.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:44:02 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/14 23:56:11 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

t_err	ps_stream_internal_append_sa(t_ps_stream *self)
{
	if (self->a < 2)
		return (false);
	if (
		ps_stream_internal_make_last_node_parallel(self)
		|| ps_stream_internal_make_last_parallel_node_swap(
			&self->tail->value.parallel->a
		)
	)
		return (true);
	ps_stream_internal_append_no_check_parallel(
		&self->tail->value.parallel->a,
		1);
	ps_stream_internal_clear_last(self);
	return (false);
}
