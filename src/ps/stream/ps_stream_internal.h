/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:03:43 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/11 20:55:15 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STREAM_INTERNAL_H
# define PS_STREAM_INTERNAL_H

# include "ps_stream.h"

size_t	ps_stream_internal_reduce_push(
			t_ps_stream *self,
			size_t count,
			bool to_b);
size_t	ps_stream_internal_reduce_swap(
			t_ps_stream *self,
			size_t count,
			bool to_b);
size_t	ps_stream_internal_reduce_rotate(
			t_ps_stream *self,
			size_t count,
			bool to_b);
size_t	ps_stream_internal_reduce_reverse_rotate(
			t_ps_stream *self,
			size_t count,
			bool to_b);

t_err	ps_stream_internal_append_empty_separator_node(
			t_ps_stream *self);
t_err	ps_stream_internal_append_empty_parallel_node(
			t_ps_stream *self);
bool	ps_stream_internal_clear_last_separator_node(
			t_ps_stream *self);
bool	ps_stream_internal_clear_last_parallel_node(
			t_ps_stream *self);

t_err	ps_stream_internal_append_push(
			t_ps_stream_node_separator *node,
			size_t count,
			bool to_b);
t_err	ps_stream_internal_append_swap(
			t_ps_stream_node_parallel *node,
			size_t count,
			bool to_b);
t_err	ps_stream_internal_append_rotate(
			t_ps_stream_node_parallel *node,
			size_t count,
			bool to_b);
t_err	ps_stream_internal_append_reverse_rotate(
			t_ps_stream_node_parallel *node,
			size_t count,
			bool to_b);

#endif
