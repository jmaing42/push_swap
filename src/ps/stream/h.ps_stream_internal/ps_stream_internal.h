/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_file_name (file name is useless too)          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42header-remover <whatever@example.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by file history     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STREAM_INTERNAL_H
# define PS_STREAM_INTERNAL_H

# include "ps_stream.h"

# include <stddef.h>
# include <stdbool.h>

# include "ft_types.h"
# include "ds_vector.h"

// a, b: each stack's length, expose.vec: vector of t_ps_stream_internal_node *
typedef struct s_ps_stream_internal
{
	const t_ps_stream	expose;
	size_t				a;
	size_t				b;
}	t_ps_stream_internal;

typedef enum e_ps_stream_internal_command
{
	PS_STREAM_INTERNAL_COMMAND_S = 0,
	PS_STREAM_INTERNAL_COMMAND_R = 1,
	PS_STREAM_INTERNAL_COMMAND_RR = 2,
}	t_ps_stream_internal_command;

// each node represents count (times) commands
typedef struct s_ps_stream_internal_command_node
{
	t_ps_stream_internal_command	command;
	size_t							count;
}	t_ps_stream_internal_command_node;

// vector a, b contains t_ps_stream_internal_command_node
typedef struct s_ps_stream_internal_node
{
	size_t		pa;
	size_t		pb;
	t_ds_vector	*a;
	size_t		ac;
	t_ds_vector	*b;
	size_t		bc;
}	t_ps_stream_internal_node;

// array a, b is flatten t_ps_stream_internal_command_node[], ac/bc is a/b count
typedef struct s_ps_stream_internal_score_matrix_pack
{
	size_t							**matrix;
	size_t							height;
	size_t							width;
	t_ps_stream_internal_command	*a;
	size_t							ac;
	t_ps_stream_internal_command	*b;
	size_t							bc;
}	t_ps_stream_internal_score_matrix_pack;

t_err	ps_stream_internal_push_pa(t_ps_stream *self, bool *out_remove);
t_err	ps_stream_internal_push_pb(t_ps_stream *self, bool *out_remove);
t_err	ps_stream_internal_push_sa(t_ps_stream *self, bool *out_remove);
t_err	ps_stream_internal_push_sb(t_ps_stream *self, bool *out_remove);
t_err	ps_stream_internal_push_ss(t_ps_stream *self, bool *out_remove);
t_err	ps_stream_internal_push_ra(t_ps_stream *self, bool *out_remove);
t_err	ps_stream_internal_push_rb(t_ps_stream *self, bool *out_remove);
t_err	ps_stream_internal_push_rr(t_ps_stream *self, bool *out_remove);
t_err	ps_stream_internal_push_rra(t_ps_stream *self, bool *out_remove);
t_err	ps_stream_internal_push_rrb(t_ps_stream *self, bool *out_remove);
t_err	ps_stream_internal_push_rrr(t_ps_stream *self, bool *out_remove);

// append new node
t_err	ps_stream_internal_append(t_ps_stream *self);
// make last node available
t_err	ps_stream_internal_make_last(t_ps_stream *self);
// make last node not include s/r/rr
t_err	ps_stream_internal_make_last_p(t_ps_stream *self);

// init vector of t_ps_stream_internal_command_node if not already exists
t_err	ps_stream_internal_node_init_vector(
			t_ds_vector **out);
// append command on t_ps_stream_internal_command_node
t_err	ps_stream_internal_node_vec_append(
			t_ds_vector *self,
			t_ps_stream_internal_command command);
// remove one if last one is given command, returns true if removed
bool	ps_stream_internal_node_vec_remove(
			t_ds_vector *self,
			t_ps_stream_internal_command command);

t_err	ps_stream_internal_node_vec_push_s(
			t_ds_vector *self,
			size_t *mut_count);
t_err	ps_stream_internal_node_vec_push_r(
			t_ds_vector *self,
			size_t *mut_count);
t_err	ps_stream_internal_node_vec_push_rr(
			t_ds_vector *self,
			size_t *mut_count);

// free t_ps_stream_internal_node *
void	ps_stream_internal_free(void *self);

// push command to vector of t_ps_command
t_err	ps_stream_internal_push(t_ds_vector *self, t_ps_command command);

// LCS
t_err	ps_stream_internal_build_score_matrix_pack(
			t_ps_stream_internal_node *node,
			t_ps_stream_internal_score_matrix_pack *out);
void	ps_stream_internal_free_score_matrix(
			size_t **matrix,
			size_t height);
void	ps_stream_internal_free_score_matrix_pack(
			t_ps_stream_internal_score_matrix_pack pack);
t_err	ps_stream_internal_s_r_rr(
			t_ps_stream_internal_node *node,
			t_ds_vector **out);
t_err	ps_stream_internal_flat(
			t_ds_vector *vector,
			size_t **out);

#endif
