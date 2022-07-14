/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_append_pb.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:41:57 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/14 23:56:55 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

#include "ft_size_t.h"

t_err	ps_stream_internal_append_pb(t_ps_stream *self, size_t count)
{
	count = ft_size_t_max(count, self->a);
	if (!count)
		return (false);
	if (ps_stream_internal_make_last_node_separator(self))
		return (true);
	ps_stream_internal_append_no_check_push_to_b(self, count);
	ps_stream_internal_clear_last(self);
	return (false);
}
