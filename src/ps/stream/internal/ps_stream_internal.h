/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:03:43 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/13 09:15:25 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STREAM_INTERNAL_H
# define PS_STREAM_INTERNAL_H

# include "ps_stream.h"

void	ps_stream_internal_clear(
			t_ps_stream *self);
bool	ps_stream_internal_clear_last(
			t_ps_stream *self);
bool	ps_stream_internal_clear_last_node(
			t_ps_stream_node *self);
bool	ps_stream_internal_clear_last_node_separator(
			t_ps_stream_node_separator *self);
bool	ps_stream_internal_clear_last_node_parallel(
			t_ps_stream_node_parallel *self);
bool	ps_stream_internal_clear_last_parallel_node(
			t_ps_stream_node_parallel_list *node);
bool	ps_stream_internal_clear_last_parallel_node_swap(
			t_ps_stream_node_parallel_list *node);
bool	ps_stream_internal_clear_last_parallel_node_rotate(
			t_ps_stream_node_parallel_list *node);
bool	ps_stream_internal_clear_last_parallel_node_reverse_rotate(
			t_ps_stream_node_parallel_list *node);

t_err	ps_stream_internal_make_last_separator_node(
			t_ps_stream *self);
t_err	ps_stream_internal_make_last_parallel_node(
			t_ps_stream *self);

t_err	ps_stream_internal_append_no_check_push_to_a(
			t_ps_stream *self,
			size_t count);
t_err	ps_stream_internal_append_no_check_push_to_b(
			t_ps_stream *self,
			size_t count);
t_err	ps_stream_internal_append_no_check_swap(
			t_ps_stream_node_parallel_list *node);
t_err	ps_stream_internal_append_no_check_rotate(
			t_ps_stream_node_parallel_list *node,
			size_t count);
t_err	ps_stream_internal_append_no_check_reverse_rotate(
			t_ps_stream_node_parallel_list *node,
			size_t count);

t_err	ps_stream_internal_append_pa(t_ps_stream *self, size_t count);
t_err	ps_stream_internal_append_pb(t_ps_stream *self, size_t count);
t_err	ps_stream_internal_append_sa(t_ps_stream *self);
t_err	ps_stream_internal_append_sb(t_ps_stream *self);
t_err	ps_stream_internal_append_ss(t_ps_stream *self);
t_err	ps_stream_internal_append_ra(t_ps_stream *self, size_t count);
t_err	ps_stream_internal_append_rb(t_ps_stream *self, size_t count);
t_err	ps_stream_internal_append_rr(t_ps_stream *self, size_t count);
t_err	ps_stream_internal_append_rra(t_ps_stream *self, size_t count);
t_err	ps_stream_internal_append_rrb(t_ps_stream *self, size_t count);
t_err	ps_stream_internal_append_rrr(t_ps_stream *self, size_t count);

#endif
