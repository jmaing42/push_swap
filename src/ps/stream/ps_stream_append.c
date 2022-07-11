/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 08:59:14 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/11 09:27:15 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

static t_err	push(t_ps_stream *self, size_t count, bool to_b)
{
	size_t	remain;

	if ((to_b && !self->a) || (!to_b && !self->b))
		return (false);
	remain = count - ps_stream_internal_reduce_push(self, count, to_b);
	return (
		(
			(
				!self->head
				|| *self->tail->value.type != PS_STREAM_NODE_TYPE_SEPARATOR
			)
			&& ps_stream_internal_append_empty_separator_node(self)
		)
		|| ps_stream_internal_separator_append_push(
			self->tail->value.separator,
			count
		)
	);
}

t_err	ps_stream_append(
	t_ps_stream *self,
	t_ps_stream_operation operation,
	size_t count,
	bool to_b
)
{
	if (operation == PS_STREAM_OPERATION_PUSH)
		push(self, count, to_b);
	else if (operation == PS_STREAM_OPERATION_SWAP)
		swap(self, count, to_b);
	else if (operation == PS_STREAM_OPERATION_ROTATE)
		rotate(self, count, to_b);
	else
		reverse_rotate(self, count, to_b);
}
