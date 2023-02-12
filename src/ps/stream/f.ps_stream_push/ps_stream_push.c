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

#include "ps_stream_internal.h"
#include "ps.h"
#include "ft_types.h"

t_err	ps_stream_push(t_ps_stream *self, t_ps_command command)
{
	if (command == PS_PA)
		return (ps_stream_internal_push_pa(self));
	if (command == PS_PB)
		return (ps_stream_internal_push_pb(self));
	if (command == PS_SA)
		return (ps_stream_internal_push_sa(self));
	if (command == PS_SB)
		return (ps_stream_internal_push_sb(self));
	if (command == PS_SS)
		return (ps_stream_internal_push_ss(self));
	if (command == PS_RA)
		return (ps_stream_internal_push_ra(self));
	if (command == PS_RB)
		return (ps_stream_internal_push_rb(self));
	if (command == PS_RR)
		return (ps_stream_internal_push_rr(self));
	if (command == PS_RRA)
		return (ps_stream_internal_push_rra(self));
	if (command == PS_RRB)
		return (ps_stream_internal_push_rrb(self));
	if (command == PS_RRR)
		return (ps_stream_internal_push_rrr(self));
	return (true);
}
