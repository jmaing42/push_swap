#include "ps_stream.h"
#include "ps_stream_internal.h"

bool	ps_stream_internal_clear_last_parallel_node(
	t_ps_stream_node_parallel_list_node *node
)
{
	if (node->type == PS_STREAM_NODE_PARALLEL_OPERATION_SWAP)
		return ps_stream_internal_clear_last_parallel_node_swap(node);
	if (node->type == PS_STREAM_NODE_PARALLEL_OPERATION_ROTATE)
		return ps_stream_internal_clear_last_parallel_node_rotate(node);
	else
		return ps_stream_internal_clear_last_parallel_node_reverse_rotate(node);
}
