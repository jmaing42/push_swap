/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_append_pa.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:40:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/20 20:35:50 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

#include "ft_primitive_size_t.h"

t_err	ps_stream_internal_append_pa(t_ps_stream *self, size_t count)
{
	count = ft_primitive_size_t_min(count, self->b);
	if (!count)
		return (false);
	if (ps_stream_internal_make_last_node_separator(self))
		return (true);
	ps_stream_internal_append_no_check_push_to_a(self, count);
	ps_stream_internal_clear(self);
	return (false);
}
