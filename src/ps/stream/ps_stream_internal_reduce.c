/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_reduce.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:02:02 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/12 20:49:53 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream.h"
#include "ps_stream_internal.h"

#include "ft_size_t.h"

size_t	ps_stream_internal_reduce_push(
	t_ps_stream *self,
	size_t count,
	bool to_b
)
{
	size_t	min;

	if (!self->tail || *self->tail->value.type != PS_STREAM_NODE_TYPE_SEPARATOR)
		return (0);
	min = self->tail->value.separator->push_to_right;
	if (to_b)
		min = self->tail->value.separator->push_to_left;
	min = ft_size_t_min(min, count);
	if (to_b)
		self->tail->value.separator->push_to_left -= min;
	else
		self->tail->value.separator->push_to_right -= min;
	ps_stream_internal_clear_last_separator_node(self);
	return (min);
}

size_t	ps_stream_internal_reduce_swap(
	t_ps_stream *self,
	size_t count,
	bool to_b
)
{
	size_t	min;

	if (
		!self->tail
		|| *self->tail->value.type != PS_STREAM_NODE_TYPE_PARALLEL
		|| (!to_b && (!self->tail->value.parallel->a_tail
				|| self->tail->value.parallel->a_tail->type
				!= PS_STREAM_NODE_PARALLEL_OPERATION_SWAP))
		|| (to_b && (!self->tail->value.parallel->b_tail
				|| self->tail->value.parallel->b_tail->type
				!= PS_STREAM_NODE_PARALLEL_OPERATION_SWAP)))
		return (0);
	if (!to_b)
		min = self->tail->value.parallel->a_tail->count;
	else
		min = self->tail->value.parallel->b_tail->count;
	min = ft_size_t_min(min, count);
	if (!to_b)
		self->tail->value.parallel->a_tail->count -= min;
	else
		self->tail->value.parallel->b_tail->count -= min;
	ps_stream_internal_clear_last_parallel_node(self);
	return (min);
}

size_t	ps_stream_internal_reduce_rotate(
	t_ps_stream *self,
	size_t count,
	bool to_b
)
{
	size_t	min;

	if (
		!self->tail
		|| *self->tail->value.type != PS_STREAM_NODE_TYPE_PARALLEL
		|| (!to_b && (!self->tail->value.parallel->a_tail
				|| self->tail->value.parallel->a_tail->type
				!= PS_STREAM_NODE_PARALLEL_OPERATION_REVERSE_ROTATE))
		|| (to_b && (!self->tail->value.parallel->b_tail
				|| self->tail->value.parallel->b_tail->type
				!= PS_STREAM_NODE_PARALLEL_OPERATION_REVERSE_ROTATE)))
		return (0);
	if (!to_b)
		min = self->tail->value.parallel->a_tail->count;
	else
		min = self->tail->value.parallel->b_tail->count;
	min = ft_size_t_min(min, count);
	if (!to_b)
		self->tail->value.parallel->a_tail->count -= min;
	else
		self->tail->value.parallel->b_tail->count -= min;
	ps_stream_internal_clear_last_parallel_node(self);
	return (min);
}

size_t	ps_stream_internal_reduce_reverse_rotate(
	t_ps_stream *self,
	size_t count,
	bool to_b
)
{
	size_t	min;

	if (
		!self->tail
		|| *self->tail->value.type != PS_STREAM_NODE_TYPE_PARALLEL
		|| (!to_b && (!self->tail->value.parallel->a_tail
				|| self->tail->value.parallel->a_tail->type
				!= PS_STREAM_NODE_PARALLEL_OPERATION_ROTATE))
		|| (to_b && (!self->tail->value.parallel->b_tail
				|| self->tail->value.parallel->b_tail->type
				!= PS_STREAM_NODE_PARALLEL_OPERATION_ROTATE)))
		return (0);
	if (!to_b)
		min = self->tail->value.parallel->a_tail->count;
	else
		min = self->tail->value.parallel->b_tail->count;
	min = ft_size_t_min(min, count);
	if (!to_b)
		self->tail->value.parallel->a_tail->count -= min;
	else
		self->tail->value.parallel->b_tail->count -= min;
	ps_stream_internal_clear_last_parallel_node(self);
	return (min);
}