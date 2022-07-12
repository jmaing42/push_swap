/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_append.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:37:59 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/12 22:17:52 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

#include <stdlib.h>

#include "ft_pointer.h"

t_err	ps_stream_internal_append_push(
	t_ps_stream_node_separator *node,
	size_t count,
	bool to_b
)
{
	if (!to_b)
		node->push_to_left += count;
	else
		node->push_to_right += count;
	return (false);
}

typedef t_ps_stream_node_parallel_list_node	*t_n;

t_err	append_node(
	t_ps_stream_node_parallel *node,
	size_t count,
	t_ps_stream_node_parallel_operation type,
	bool to_b
)
{
	const t_n	last = malloc(sizeof(t_ps_stream_node_parallel_list_node));

	if (!last)
		return (true);
	last->count = count;
	last->type = type;
	last->next = NULL;
	last->prev = ft_pointer_if(!to_b, node->a_tail, node->b_tail);
	*((t_n *)ft_pointer_if(!to_b, &node->a_tail, &node->b_tail)) = last;
	if (last->prev)
		last->prev->next = last;
	else
		*((t_n *)ft_pointer_if(!to_b, &node->a_head, &node->b_head)) = last;
	return (false);
}

t_err	ps_stream_internal_append_swap(
	t_ps_stream_node_parallel *node,
	size_t count,
	bool to_b
)
{
	if (!to_b
		&& node->a_tail
		&& node->a_tail->type
		== PS_STREAM_NODE_PARALLEL_OPERATION_SWAP)
	{
		node->a_tail->count += count;
		return (false);
	}
	if (to_b
		&& node->b_tail
		&& node->b_tail->type
		== PS_STREAM_NODE_PARALLEL_OPERATION_SWAP)
	{
		node->b_tail->count += count;
		return (false);
	}
	return (
		append_node(
			node,
			count,
			PS_STREAM_NODE_PARALLEL_OPERATION_SWAP,
			to_b
		)
	);
}

t_err	ps_stream_internal_append_rotate(
	t_ps_stream_node_parallel *node,
	size_t count,
	bool to_b
)
{
	if (!to_b
		&& node->a_tail
		&& node->a_tail->type
		== PS_STREAM_NODE_PARALLEL_OPERATION_ROTATE)
	{
		node->a_tail->count += count;
		return (false);
	}
	if (to_b
		&& node->b_tail
		&& node->b_tail->type
		== PS_STREAM_NODE_PARALLEL_OPERATION_ROTATE)
	{
		node->b_tail->count += count;
		return (false);
	}
	return (
		append_node(
			node,
			count,
			PS_STREAM_NODE_PARALLEL_OPERATION_ROTATE,
			to_b
		)
	);
}

t_err	ps_stream_internal_append_reverse_rotate(
	t_ps_stream_node_parallel *node,
	size_t count,
	bool to_b
)
{
	if (!to_b
		&& node->a_tail
		&& node->a_tail->type
		== PS_STREAM_NODE_PARALLEL_OPERATION_REVERSE_ROTATE)
	{
		node->a_tail->count += count;
		return (false);
	}
	if (to_b
		&& node->b_tail
		&& node->b_tail->type
		== PS_STREAM_NODE_PARALLEL_OPERATION_REVERSE_ROTATE)
	{
		node->b_tail->count += count;
		return (false);
	}
	return (
		append_node(
			node,
			count,
			PS_STREAM_NODE_PARALLEL_OPERATION_REVERSE_ROTATE,
			to_b
		)
	);
}
