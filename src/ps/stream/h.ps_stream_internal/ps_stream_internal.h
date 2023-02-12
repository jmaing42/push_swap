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

typedef struct s_ps_stream_internal
{
	const t_ps_stream	expose;
	size_t				a;
	size_t				b;
}	t_ps_stream_internal;

typedef enum e_ps_stream_internal_command
{
	PS_STREAM_INTERNAL_COMMAND_S,
	PS_STREAM_INTERNAL_COMMAND_R,
	PS_STREAM_INTERNAL_COMMAND_RR,
}	t_ps_stream_internal_command;

typedef struct s_ps_stream_internal_command_node
{
	t_ps_stream_internal_command	command;
	size_t							count;
}	t_ps_stream_internal_command_node;

typedef struct s_ps_stream_internal_node
{
	size_t		pa;
	size_t		pb;
	t_ds_vector	*a;
	size_t		ac;
	t_ds_vector	*b;
	size_t		bc;
}	t_ps_stream_internal_node;

t_err	ps_stream_internal_push_pa(t_ps_stream *self);
t_err	ps_stream_internal_push_pb(t_ps_stream *self);
t_err	ps_stream_internal_push_sa(t_ps_stream *self);
t_err	ps_stream_internal_push_sb(t_ps_stream *self);
t_err	ps_stream_internal_push_ss(t_ps_stream *self);
t_err	ps_stream_internal_push_ra(t_ps_stream *self);
t_err	ps_stream_internal_push_rb(t_ps_stream *self);
t_err	ps_stream_internal_push_rr(t_ps_stream *self);
t_err	ps_stream_internal_push_rra(t_ps_stream *self);
t_err	ps_stream_internal_push_rrb(t_ps_stream *self);
t_err	ps_stream_internal_push_rrr(t_ps_stream *self);

t_err	ps_stream_internal_node_push_s(
			t_ps_stream_internal_node *self,
			bool *out_remove);
t_err	ps_stream_internal_node_push_r(
			t_ps_stream_internal_node *self,
			bool *out_remove);
t_err	ps_stream_internal_node_push_rr(
			t_ps_stream_internal_node *self,
			bool *out_remove);

void	ps_stream_internal_free(void *self);

#endif
