/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:03:43 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/13 09:06:11 by Juyeong Maing    ###   ########.fr       */
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

size_t	ps_stream_internal_remove_last_pa(t_ps_stream *self, size_t max_count);
size_t	ps_stream_internal_remove_last_pb(t_ps_stream *self, size_t max_count);
bool	ps_stream_internal_remove_last_sa(t_ps_stream *self);
bool	ps_stream_internal_remove_last_sb(t_ps_stream *self);
size_t	ps_stream_internal_remove_last_ra(t_ps_stream *self, size_t max_count);
size_t	ps_stream_internal_remove_last_rb(t_ps_stream *self, size_t max_count);
size_t	ps_stream_internal_remove_last_rra(t_ps_stream *self, size_t max_count);
size_t	ps_stream_internal_remove_last_rrb(t_ps_stream *self, size_t max_count);

t_err	ps_stream_internal_append_no_check_pa(t_ps_stream *self, size_t count);
t_err	ps_stream_internal_append_no_check_pb(t_ps_stream *self, size_t count);
t_err	ps_stream_internal_append_no_check_sa(t_ps_stream *self);
t_err	ps_stream_internal_append_no_check_sb(t_ps_stream *self);
t_err	ps_stream_internal_append_no_check_ss(t_ps_stream *self);
t_err	ps_stream_internal_append_no_check_ra(t_ps_stream *self, size_t count);
t_err	ps_stream_internal_append_no_check_rb(t_ps_stream *self, size_t count);
t_err	ps_stream_internal_append_no_check_rr(t_ps_stream *self, size_t count);
t_err	ps_stream_internal_append_no_check_rra(t_ps_stream *self, size_t count);
t_err	ps_stream_internal_append_no_check_rrb(t_ps_stream *self, size_t count);
t_err	ps_stream_internal_append_no_check_rrr(t_ps_stream *self, size_t count);

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
