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

#include "ps_stream.h"

#include <stdbool.h>

#include "ps_stream_internal.h"
#include "ps.h"
#include "c.h"
#include "ft_types.h"

typedef t_err	(*t_f)(t_ps_stream *self, bool *out_remove);

static t_f	func(t_ps_command command)
{
	if (command == PS_PA)
		return (&ps_stream_internal_push_pa);
	if (command == PS_PB)
		return (&ps_stream_internal_push_pb);
	if (command == PS_SA)
		return (&ps_stream_internal_push_sa);
	if (command == PS_SB)
		return (&ps_stream_internal_push_sb);
	if (command == PS_SS)
		return (&ps_stream_internal_push_ss);
	if (command == PS_RA)
		return (&ps_stream_internal_push_ra);
	if (command == PS_RB)
		return (&ps_stream_internal_push_rb);
	if (command == PS_RR)
		return (&ps_stream_internal_push_rr);
	if (command == PS_RRA)
		return (&ps_stream_internal_push_rra);
	if (command == PS_RRB)
		return (&ps_stream_internal_push_rrb);
	if (command == PS_RRR)
		return (&ps_stream_internal_push_rrr);
	return (NULL);
}

t_err	ps_stream_push(t_ps_stream *self, t_ps_command command)
{
	const t_f					f = func(command);
	bool						removed;
	t_ps_stream_internal_node	*node;

	if (!f)
		return (true);
	if (f(self, &removed))
		return (true);
	if (removed)
	{
		self->vec->v->pop(self->vec, &node);
		c_free(node);
	}
	return (false);
}
