/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stream.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 01:12:24 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/28 01:34:53 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_STREAM_H
# define PUSH_SWAP_STREAM_H

# include <stddef.h>

# include "ft_types.h"

typedef enum e_push_swap_stream_operation
{
	PUSH_SWAP_STREAM_OPERATION_PUSH_TO_LEFT,
	PUSH_SWAP_STREAM_OPERATION_PUSH_TO_RIGHT,
	PUSH_SWAP_STREAM_OPERATION_SWAP_LEFT,
	PUSH_SWAP_STREAM_OPERATION_SWAP_RIGHT,
	PUSH_SWAP_STREAM_OPERATION_SWAP_BOTH,
	PUSH_SWAP_STREAM_OPERATION_ROTATE_LEFT,
	PUSH_SWAP_STREAM_OPERATION_ROTATE_RIGHT,
	PUSH_SWAP_STREAM_OPERATION_ROTATE_BOTH,
	PUSH_SWAP_STREAM_OPERATION_REVERSE_ROTATE_LEFT,
	PUSH_SWAP_STREAM_OPERATION_REVERSE_ROTATE_RIGHT,
	PUSH_SWAP_STREAM_OPERATION_REVERSE_ROTATE_BOTH,
}	t_push_swap_stream_operation;

typedef struct s_push_swap_stream_state_part
{
	int		*arr;
	size_t	capacity;
	size_t	offset;
	size_t	size;
}	t_push_swap_stream_state_part;

typedef struct s_push_swap_stream_state
{
	t_push_swap_stream_state_part	a;
	t_push_swap_stream_state_part	b;
}	t_push_swap_stream_state;

typedef enum e_push_swap_stream_node_type
{
	PUSH_SWAP_STREAM_NODE_TYPE_SEPARATOR,
	PUSH_SWAP_STREAM_NODE_TYPE_PARALLEL,
}	t_push_swap_stream_node_type;

typedef struct s_push_swap_stream_node_separator
{
	t_push_swap_stream_node_type	type;
	size_t							push_to_left;
	size_t							push_to_right;
}	t_push_swap_stream_node_separator;

typedef enum e_push_swap_stream_node_parallel_operation
{
	PUSH_SWAP_STREAM_NODE_PARALLEL_OPERATION_SWAP,
	PUSH_SWAP_STREAM_NODE_PARALLEL_OPERATION_ROTATE,
	PUSH_SWAP_STREAM_NODE_PARALLEL_OPERATION_REVERSE_ROTATE,
}	t_push_swap_stream_node_parallel_operation;

typedef struct s_push_swap_stream_node_parallel_list_node
{
	struct s_push_swap_stream_node_parallel_list_node	*prev;
	struct s_push_swap_stream_node_parallel_list_node	*next;
	size_t												count;
	t_push_swap_stream_node_parallel_operation			type;
}	t_push_swap_stream_node_parallel_list_node;

typedef struct s_push_swap_stream_node_parallel
{
	t_push_swap_stream_node_type				type;
	t_push_swap_stream_node_parallel_list_node	*head;
	t_push_swap_stream_node_parallel_list_node	*tail;
}	t_push_swap_stream_node_parallel;

typedef struct s_push_swap_stream
{
	t_push_swap_stream_state	*state;
}	t_push_swap_stream;

void	push_swap_stream_print(
			t_push_swap_stream *self);

#endif
