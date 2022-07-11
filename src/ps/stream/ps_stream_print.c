/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:58:26 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/11 21:07:01 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream.h"

#include "ft_io.h"

static t_err	process_parallel_a(
	t_ps_stream_node_parallel_list_node *node,
	int fd
)
{
	size_t	i;

	while (node)
	{
		i = -1;
		if (node->type == PS_STREAM_NODE_PARALLEL_OPERATION_SWAP)
			while (++i < node->count)
				if (ft_puts(fd, "sa\n"))
					return (true);
		if (node->type == PS_STREAM_NODE_PARALLEL_OPERATION_ROTATE)
			while (++i < node->count)
				if (ft_puts(fd, "ra\n"))
					return (true);
		if (node->type == PS_STREAM_NODE_PARALLEL_OPERATION_REVERSE_ROTATE)
			while (++i < node->count)
				if (ft_puts(fd, "rra\n"))
					return (true);
	}
	return (false);
}

static t_err	process_parallel_b(
	t_ps_stream_node_parallel_list_node *node,
	int fd
)
{
	size_t	i;

	while (node)
	{
		i = -1;
		if (node->type == PS_STREAM_NODE_PARALLEL_OPERATION_SWAP)
			while (++i < node->count)
				if (ft_puts(fd, "sb\n"))
					return (true);
		if (node->type == PS_STREAM_NODE_PARALLEL_OPERATION_ROTATE)
			while (++i < node->count)
				if (ft_puts(fd, "rb\n"))
					return (true);
		if (node->type == PS_STREAM_NODE_PARALLEL_OPERATION_REVERSE_ROTATE)
			while (++i < node->count)
				if (ft_puts(fd, "rrb\n"))
					return (true);
	}
	return (false);
}

static t_err	process_node(t_ps_stream_node *node, int fd)
{
	size_t	i;

	if (*node->value.type == PS_STREAM_NODE_TYPE_SEPARATOR)
	{
		i = -1;
		while (++i < node->value.separator->push_to_left)
			if (ft_puts(fd, "pa\n"))
				return (true);
		i = -1;
		while (++i < node->value.separator->push_to_right)
			if (ft_puts(fd, "pb\n"))
				return (true);
		return (false);
	}
	return (
		process_parallel_a(node->value.parallel->a_head, fd)
		|| process_parallel_b(node->value.parallel->b_head, fd)
	);
}

t_err	ps_stream_print(
	t_ps_stream *self,
	int fd
)
{
	t_ps_stream_node	*node;

	node = self->head;
	while (node)
	{
		if (process_node(node, fd))
			return (true);
		node = node->next;
	}
	return (false);
}
