/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 01:12:24 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/13 09:02:29 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STREAM_H
# define PS_STREAM_H

# include <stddef.h>

# include "ft_types.h"
# include "fto_stream_out.h"

typedef enum e_ps_stream_node_type
{
	PS_STREAM_NODE_TYPE_SEPARATOR,
	PS_STREAM_NODE_TYPE_PARALLEL,
}	t_ps_stream_node_type;

typedef struct s_ps_stream_node_separator
{
	t_ps_stream_node_type	type;
	size_t					pa;
	size_t					pb;
}	t_ps_stream_node_separator;

typedef enum e_ps_stream_node_parallel_operation
{
	PS_STREAM_NODE_PARALLEL_OPERATION_SWAP,
	PS_STREAM_NODE_PARALLEL_OPERATION_ROTATE,
	PS_STREAM_NODE_PARALLEL_OPERATION_REVERSE_ROTATE,
}	t_ps_stream_node_parallel_operation;

typedef struct s_ps_stream_node_parallel_list_node
{
	struct s_ps_stream_node_parallel_list_node	*prev;
	struct s_ps_stream_node_parallel_list_node	*next;
	size_t										count;
	t_ps_stream_node_parallel_operation			type;
}	t_ps_stream_node_parallel_list_node;

typedef struct s_ps_stream_node_parallel_list
{
	t_ps_stream_node_parallel_list_node	*head;
	t_ps_stream_node_parallel_list_node	*tail;
}	t_ps_stream_node_parallel_list;

typedef struct s_ps_stream_node_parallel
{
	t_ps_stream_node_type			type;
	t_ps_stream_node_parallel_list	a;
	t_ps_stream_node_parallel_list	b;
}	t_ps_stream_node_parallel;

typedef union u_ps_stream_node_value
{
	t_ps_stream_node_type		*type;
	t_ps_stream_node_separator	*separator;
	t_ps_stream_node_parallel	*parallel;
}	t_ps_stream_node_value;

typedef struct s_ps_stream_node
{
	struct s_ps_stream_node	*prev;
	struct s_ps_stream_node	*next;
	t_ps_stream_node_value	value;
}	t_ps_stream_node;

typedef struct s_ps_stream
{
	t_ps_stream_node	*head;
	t_ps_stream_node	*tail;
	size_t				a;
	size_t				b;
}	t_ps_stream;

t_ps_stream	*new_ps_stream(
				size_t a,
				size_t b);
void		ps_stream_free(
				t_ps_stream *self);
t_err		ps_stream_print(
				t_ps_stream *self,
				int fd);
t_err		ps_stream_flush(
				t_ps_stream *self,
				t_fto_stream_out *stream_to);

t_err		ps_stream_append_pa(t_ps_stream *self, size_t count, bool reverse);
t_err		ps_stream_append_pb(t_ps_stream *self, size_t count, bool reverse);
t_err		ps_stream_append_sa(t_ps_stream *self, bool reverse);
t_err		ps_stream_append_sb(t_ps_stream *self, bool reverse);
t_err		ps_stream_append_ss(t_ps_stream *self);
t_err		ps_stream_append_ra(t_ps_stream *self, size_t count, bool reverse);
t_err		ps_stream_append_rb(t_ps_stream *self, size_t count, bool reverse);
t_err		ps_stream_append_rr(t_ps_stream *self, size_t count);
t_err		ps_stream_append_rra(t_ps_stream *self, size_t count, bool reverse);
t_err		ps_stream_append_rrb(t_ps_stream *self, size_t count, bool reverse);
t_err		ps_stream_append_rrr(t_ps_stream *self, size_t count);

#endif
