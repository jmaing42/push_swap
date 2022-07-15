#include "ft_const_pointer.h"
#include "ft_io.h"
#include "ps_stream.h"

#include <stdbool.h>
#include <stdlib.h>

static t_err	ps_stream_print_separator(
	t_ps_stream_node_separator *node,
	int fd
)
{
	size_t	i;

	i = -1;
	while (++i < node->pa)
		if (ft_puts(fd, "pa"))
			return (true);
	i = -1;
	while (++i < node->pb)
		if (ft_puts(fd, "pb"))
			return (true);
	return (false);
}

static t_err	ps_stream_print_parallel_list(
	t_ps_stream_node_parallel_list *list,
	int fd,
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
				if (ft_puts(fd, ft_const_pointer_if(b, "sb", "sa")))
					return (true);
		if (current->type == PS_STREAM_NODE_PARALLEL_OPERATION_ROTATE)
			while (++i < current->count)
				if (ft_puts(fd, ft_const_pointer_if(b, "rb", "ra")))
					return (true);
		if (current->type == PS_STREAM_NODE_PARALLEL_OPERATION_REVERSE_ROTATE)
			while (++i < current->count)
				if (ft_puts(fd, ft_const_pointer_if(b, "rrb", "rra")))
					return (true);
		current = current->next;
	}
	return (false);
}

static t_err	ps_stream_print_node(
	t_ps_stream_node *node,
	int fd
)
{
	return (
		(
			*node->value.type == PS_STREAM_NODE_TYPE_SEPARATOR
			&& (ps_stream_print_separator(node->value.separator, fd))
		)
		|| (
			*node->value.type == PS_STREAM_NODE_TYPE_PARALLEL
			&& (
				ps_stream_print_parallel_list(&node->value.parallel->a, fd)
				|| ps_stream_print_parallel_list(&node->value.parallel->b, fd)
			)
		)
	);
}

t_err	ps_stream_print(
	t_ps_stream *self,
	int fd
)
{
	t_ps_stream_node	*current;

	current = self->head;
	while (current)
	{
		if (ps_stream_print_node(current, fd))
			return (true);
		current = current->next;
	}
	return (false);
}
