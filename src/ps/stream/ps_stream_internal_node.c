/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_node.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:02:13 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/11 20:02:14 by Juyeong Maing    ###   ########.fr       */
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

void	ps_stream_internal_clear_last_separator_node(t_ps_stream *self)
{
	t_ps_stream_node *const	node = self->tail;

	if (
		node->value.separator->push_to_left
		|| node->value.separator->push_to_right
	)
		return ;
	if (!node->prev)
		self->head = NULL;
	else
		node->prev->next = NULL;
	free(node->value.separator);
	free(node);
}

void	ps_stream_internal_clear_last_parallel_node(t_ps_stream *self)
{
	t_ps_stream_node *const	node = self->tail;

	if (
		node->value.parallel->a_head
		|| node->value.parallel->b_head
	)
		return ;
	if (!node->prev)
		self->head = NULL;
	else
		node->prev->next = NULL;
	free(node->value.parallel);
	free(node);
}
