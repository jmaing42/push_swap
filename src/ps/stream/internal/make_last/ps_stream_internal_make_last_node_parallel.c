#include "ps_stream_internal.h"

#include <stdlib.h>

t_err	ps_stream_internal_make_last_node_parallel(t_ps_stream *self)
{
	t_ps_stream_node_in_parallel	*node;

	if (self->tail && *self->tail->value.type == PS_STREAM_NODE_TYPE_PARALLEL)
		return (false);
	node = malloc(sizeof(t_ps_stream_node_in_parallel));
	if (!node)
		return (true);
	node->super.value.parallel = &node->value;
	node->super.next = NULL;
	node->super.prev = self->tail;
	node->value.type = PS_STREAM_NODE_TYPE_PARALLEL;
	node->value.a.head = NULL;
	node->value.a.tail = NULL;
	node->value.b.head = NULL;
	node->value.b.tail = NULL;
	if (self->tail)
		self->tail->next = &node->super;
	else
		self->head = &node->super;
	self->tail = &node->super;
	return (false);
}
