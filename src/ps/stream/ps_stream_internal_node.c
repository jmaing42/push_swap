/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_node.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:02:13 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/12 08:58:49 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream.h"
#include "ps_stream_internal.h"

#include <stdlib.h>

t_err	ps_stream_internal_append_empty_separator_node(
	t_ps_stream *self
)
{
	t_ps_stream_node *const				node
		= malloc(sizeof(t_ps_stream_node));
	t_ps_stream_node_separator *const	separator
		= malloc(sizeof(t_ps_stream_node_separator));

	if (!node || !separator)
	{
		free(node);
		free(separator);
		return (true);
	}
	node->prev = self->tail;
	node->next = NULL;
	node->value.separator = separator;
	separator->type = PS_STREAM_NODE_TYPE_SEPARATOR;
	separator->push_to_left = 0;
	separator->push_to_right = 0;
	if (!self->tail)
		self->head = node;
	else
		self->tail->next = node;
	self->tail = node;
	return (false);
}

t_err	ps_stream_internal_append_empty_parallel_node(
	t_ps_stream *self
)
{
	t_ps_stream_node *const				node
		= malloc(sizeof(t_ps_stream_node));
	t_ps_stream_node_parallel *const	parallel
		= malloc(sizeof(t_ps_stream_node_parallel));

	if (!node || !parallel)
	{
		free(node);
		free(parallel);
		return (true);
	}
	node->prev = self->tail;
	node->next = NULL;
	node->value.parallel = parallel;
	parallel->type = PS_STREAM_NODE_TYPE_PARALLEL;
	parallel->a_head = NULL;
	parallel->a_tail = NULL;
	parallel->b_head = NULL;
	parallel->b_tail = NULL;
	if (!self->tail)
		self->head = node;
	else
		self->tail->next = node;
	self->tail = node;
	return (false);
}

bool	ps_stream_internal_clear_last_separator_node(t_ps_stream *self)
{
	t_ps_stream_node *const	node = self->tail;

	if (
		node->value.separator->push_to_left
		|| node->value.separator->push_to_right
	)
		return (false);
	if (!node->prev)
		self->head = NULL;
	else
		node->prev->next = NULL;
	self->tail = node->prev;
	free(node->value.separator);
	free(node);
	return (true);
}

static bool	clear_parallel_node(t_ps_stream_node_parallel *node)
{
	t_ps_stream_node_parallel_list_node	*tmp;

	tmp = node->a_tail;
	if (tmp && tmp->count == 0)
	{
		if (!tmp->prev)
			node->a_head = NULL;
		else
			tmp->prev->next = NULL;
		node->a_tail = tmp->prev;
		free(tmp);
		return (true);
	}
	tmp = node->b_tail;
	if (tmp && tmp->count == 0)
	{
		if (!tmp->prev)
			node->b_head = NULL;
		else
			tmp->prev->next = NULL;
		node->b_tail = tmp->prev;
		free(tmp);
		return (true);
	}
	return (false);
}

bool	ps_stream_internal_clear_last_parallel_node(t_ps_stream *self)
{
	t_ps_stream_node *const	node = self->tail;
	bool					result;

	result = clear_parallel_node(node->value.parallel);
	if (
		node->value.parallel->a_head
		|| node->value.parallel->b_head
	)
		return (result);
	if (!node->prev)
		self->head = NULL;
	else
		node->prev->next = NULL;
	self->tail = node->prev;
	free(node->value.parallel);
	free(node);
	return (true);
}
