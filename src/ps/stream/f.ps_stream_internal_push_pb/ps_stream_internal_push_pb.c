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

t_err	ps_stream_internal_push_pb(t_ps_stream *self, bool *out_remove)
{
	t_ps_stream_internal *const	original = (t_ps_stream_internal *)self;
	t_ps_stream_internal_node	*node;

	if (!original->a)
		return (false);
	if (ps_stream_internal_make_last_p(self))
		return (true);
	self->vec->v->peek(self->vec, &node);
	if (node->pa)
		node->pa--;
	else
		node->pb++;
	original->a--;
	original->b++;
	*out_remove = (!node->pa && !node->pb);
	return (false);
}
