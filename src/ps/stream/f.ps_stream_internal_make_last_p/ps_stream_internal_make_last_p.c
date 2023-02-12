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

#include "ft_types.h"

t_err	ps_stream_internal_make_last_p(t_ps_stream *self)
{
	t_ps_stream_internal_node	*node;

	if (ps_stream_internal_make_last(self))
		return (true);
	self->vec->v->peek(self->vec, &node);
	if (node->a || node->b)
		return (ps_stream_internal_append(self));
	return (false);
}
