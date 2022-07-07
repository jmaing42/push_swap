/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 01:12:24 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/07 23:32:27 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STREAM_H
# define PS_STREAM_H

# include <stddef.h>

# include "ft_types.h"

typedef enum e_ps_stream_operation
{
	PS_STREAM_OPERATION_PUSH_TO_LEFT,
	PS_STREAM_OPERATION_PUSH_TO_RIGHT,
	PS_STREAM_OPERATION_SWAP_LEFT,
	PS_STREAM_OPERATION_SWAP_RIGHT,
	PS_STREAM_OPERATION_SWAP_BOTH,
	PS_STREAM_OPERATION_ROTATE_LEFT,
	PS_STREAM_OPERATION_ROTATE_RIGHT,
	PS_STREAM_OPERATION_ROTATE_BOTH,
	PS_STREAM_OPERATION_REVERSE_ROTATE_LEFT,
	PS_STREAM_OPERATION_REVERSE_ROTATE_RIGHT,
	PS_STREAM_OPERATION_REVERSE_ROTATE_BOTH,
}	t_ps_stream_operation;

typedef enum e_ps_stream_node_type
{
	PS_STREAM_NODE_TYPE_SEPARATOR,
	PS_STREAM_NODE_TYPE_PARALLEL,
}	t_ps_stream_node_type;

typedef struct s_ps_stream_node_separator
{
	t_ps_stream_node_type	type;
	size_t					push_to_left;
	size_t					push_to_right;
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

typedef struct s_ps_stream_node_parallel
{
	t_ps_stream_node_type				type;
	t_ps_stream_node_parallel_list_node	*a_head;
	t_ps_stream_node_parallel_list_node	*a_tail;
	t_ps_stream_node_parallel_list_node	*b_head;
	t_ps_stream_node_parallel_list_node	*b_tail;
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
t_err		ps_stream_print(
				t_ps_stream *self);
t_err		ps_stream_append(
				t_ps_stream *self,
				t_ps_stream_operation operation,
				size_t count);

#endif
