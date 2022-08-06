#include "ps_stream.h"

#include <stdlib.h>

#include "ft_io.h"
#include "ft_types_primitive_const_pointer.h"

static t_err	ps_stream_flush_separator(
	t_ps_stream_node_separator *node,
	t_fto_stream_out *stream_to
)
{
	size_t	i;

	i = -1;
	while (++i < node->pa)
		if (stream_to->v->write(stream_to, "pa\n", 3, NULL))
			return (true);
	i = -1;
	while (++i < node->pb)
		if (stream_to->v->write(stream_to, "pb\n", 3, NULL))
			return (true);
	return (false);
}

static t_err	ps_stream_flush_parallel_list(
	t_ps_stream_node_parallel_list *list,
	t_fto_stream_out *to,
	bool b
)
{
	t_ps_stream_node_parallel_list_node	*current;
	size_t								i;

	current = list->head;
	while (current)
	{
		i = -1;
		if (current->type == PS_STREAM_NODE_PARALLEL_OPERATION_SWAP)
			while (++i < current->count)
				if (to->v->write(to, ft_types_primitive_const_pointer_if(
							b, "sb\n", "sa\n"), 3, NULL))
					return (true);
		if (current->type == PS_STREAM_NODE_PARALLEL_OPERATION_ROTATE)
			while (++i < current->count)
				if (to->v->write(to, ft_types_primitive_const_pointer_if(
							b, "rb\n", "ra\n"), 3, NULL))
					return (true);
		if (current->type == PS_STREAM_NODE_PARALLEL_OPERATION_REVERSE_ROTATE)
			while (++i < current->count)
				if (to->v->write(to, ft_types_primitive_const_pointer_if(
							b, "rrb\n", "rra\n"), 4, NULL))
					return (true);
		current = current->next;
	}
	return (false);
}

static t_err	ps_stream_flush_node(
	t_ps_stream_node *node,
	t_fto_stream_out *stream_to
)
{
	return (
		(
			*node->value.type == PS_STREAM_NODE_TYPE_SEPARATOR
			&& (ps_stream_flush_separator(node->value.separator, stream_to))
		)
		|| (
			*node->value.type == PS_STREAM_NODE_TYPE_PARALLEL
			&& (
				ps_stream_flush_parallel_list(
					&node->value.parallel->a,
					stream_to,
					false
				)
				|| ps_stream_flush_parallel_list(
					&node->value.parallel->b,
					stream_to,
					true
				)
			)
		)
	);
}

t_err	ps_stream_flush(
	t_ps_stream *self,
	t_fto_stream_out *stream_to
)
{
	t_ps_stream_node	*current;

	current = self->head;
	while (current)
	{
		if (ps_stream_flush_node(current, stream_to))
			return (true);
		current = current->next;
	}
	return (false);
}
