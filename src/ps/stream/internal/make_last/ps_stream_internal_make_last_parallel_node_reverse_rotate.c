#include "ps_stream_internal.h"

#include <stdlib.h>

t_err	ps_stream_internal_make_last_parallel_node_reverse_rotate(
	t_ps_stream_node_parallel_list *list
)
{
	t_ps_stream_node_parallel_list_node	*node;

	if (
		list->tail
		&& list->tail->type == PS_STREAM_NODE_PARALLEL_OPERATION_REVERSE_ROTATE
	)
		return (false);
	node = malloc(sizeof(t_ps_stream_node_parallel_list_node));
	if (!node)
		return (true);
	node->next = NULL;
	node->prev = list->tail;
	node->type = PS_STREAM_NODE_PARALLEL_OPERATION_REVERSE_ROTATE;
	node->count = 0;
	if (list->tail)
		list->tail->next = node;
	else
		list->head = node;
	list->tail = node;
	return (false);
}
