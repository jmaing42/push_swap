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

#include "ps_stream_internal.h"

#include <stdbool.h>

#include "ft_types.h"

t_err	ps_stream_internal_push_sb(t_ps_stream *self, bool *out_remove)
{
	t_ps_stream_internal *const	original = (t_ps_stream_internal *)self;
	t_ps_stream_internal_node	*node;

	if (original->b < 2)
	{
		*out_remove = false;
		return (false);
	}
	if (ps_stream_internal_make_last(self))
		return (true);
	self->vec->v->peek(self->vec, &node);
	if (ps_stream_internal_node_init_vector(&node->b))
		return (true);
	if (ps_stream_internal_node_vec_push_s(node->b, &node->bc))
		return (true);
	if (!node->bc)
		o_disposable_dispose_p((t_o_disposable **)&node->b);
	*out_remove = (!node->ac && !node->bc && !node->pa && !node->pb);
	return (false);
}
