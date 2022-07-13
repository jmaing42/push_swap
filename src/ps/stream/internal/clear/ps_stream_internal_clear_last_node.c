#include "ps_stream.h"
#include "ps_stream_internal.h"

bool	ps_stream_internal_clear_last_node(t_ps_stream_node *self)
{
	if (*self->value.type == PS_STREAM_NODE_TYPE_SEPARATOR)
		return (
			ps_stream_internal_clear_last_node_separator(self->value.separator)
		);
	else
		return (
			ps_stream_internal_clear_last_node_parallel(self->value.parallel)
		);
}
