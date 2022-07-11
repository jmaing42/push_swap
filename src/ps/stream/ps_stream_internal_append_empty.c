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
	if (self->tail)
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
	if (self->tail)
		self->tail->next = node;
	self->tail = node;
	return (false);
}
