/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 08:59:14 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/11 23:31:38 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

#include "ft_size_t.h"

static t_err	push(t_ps_stream *self, size_t count, bool to_b)
{
	size_t	remain;

	if ((to_b && !self->a) || (!to_b && !self->b))
		return (false);
	if (!to_b)
		count = ft_size_t_min(count, self->b);
	else
		count = ft_size_t_min(count, self->a);
	remain = count
		- ps_stream_internal_reduce_push(self, count, to_b);
	return (
		(
			(
				!self->head
				|| *self->tail->value.type != PS_STREAM_NODE_TYPE_SEPARATOR
			)
			&& ps_stream_internal_append_empty_separator_node(self)
		)
		|| ps_stream_internal_append_push(
			self->tail->value.separator,
			remain,
			to_b
		)
	);
}

static t_err	swap(t_ps_stream *self, size_t count, bool to_b)
{
	size_t	remain;

	if ((to_b && self->a < 2) || (!to_b && self->b < 2) || count % 2 == 0)
		return (false);
	remain = count
		- ps_stream_internal_reduce_swap(self, count, to_b);
	remain = remain % 2;
	if (!remain)
		return (false);
	return (
		(
			(
				!self->head
				|| *self->tail->value.type != PS_STREAM_NODE_TYPE_PARALLEL
			)
			&& ps_stream_internal_append_empty_parallel_node(self)
		)
		|| ps_stream_internal_append_swap(
			self->tail->value.parallel,
			remain,
			to_b
		)
	);
}

static t_err	rotate(t_ps_stream *self, size_t count, bool to_b)
{
	size_t	remain;

	if ((to_b && self->a < 2) || (!to_b && self->b < 2))
		return (false);
	remain = count
		- ps_stream_internal_reduce_rotate(self, count, to_b);
	return (
		(
			(
				!self->head
				|| *self->tail->value.type != PS_STREAM_NODE_TYPE_PARALLEL
			)
			&& ps_stream_internal_append_empty_parallel_node(self)
		)
		|| ps_stream_internal_append_rotate(
			self->tail->value.parallel,
			remain,
			to_b
		)
	);
}

static t_err	reverse_rotate(t_ps_stream *self, size_t count, bool to_b)
{
	size_t	remain;

	if ((to_b && self->a < 2) || (!to_b && self->b < 2))
		return (false);
	remain = count
		- ps_stream_internal_reduce_reverse_rotate(self, count, to_b);
	return (
		(
			(
				!self->head
				|| *self->tail->value.type != PS_STREAM_NODE_TYPE_PARALLEL
			)
			&& ps_stream_internal_append_empty_parallel_node(self)
		)
		|| ps_stream_internal_append_reverse_rotate(
			self->tail->value.parallel,
			remain,
			to_b
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
		return (push(self, count, to_b));
	else if (operation == PS_STREAM_OPERATION_SWAP)
		return (swap(self, count, to_b));
	else if (operation == PS_STREAM_OPERATION_ROTATE)
		return (rotate(self, count, to_b));
	else
		return (reverse_rotate(self, count, to_b));
}
