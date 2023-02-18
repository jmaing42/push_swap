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

#include <stddef.h>

#include "ps.h"
#include "ps_stream_internal.h"
#include "ds_vector.h"
#include "o_disposable.h"

static t_err	serialize_node(
	t_ds_vector *self,
	t_ps_stream_internal_node *node
)
{
	size_t		i;
	t_ds_vector	*tmp;
	t_err		result;

	i = -1;
	while (++i < node->pa)
		if (ps_stream_internal_push(self, PS_PA))
			return (true);
	i = -1;
	while (++i < node->pb)
		if (ps_stream_internal_push(self, PS_PB))
			return (true);
	if (ps_stream_internal_s_r_rr(node, &tmp))
		return (true);
	tmp->v->reverse(tmp);
	result = self->v->append(self, tmp);
	o_disposable_dispose((t_o_disposable *)tmp);
	return (result);
}

t_ds_vector	*ps_stream_to_vector(t_ps_stream *self)
{
	t_ds_vector *const			result
		= ds_vector_new(sizeof(t_ps_command), NULL);
	t_ps_stream_internal_node	*node;
	size_t						i;

	if (!result)
		return (NULL);
	i = -1;
	while (++i < self->vec->v->length(self->vec))
	{
		self->vec->v->get(self->vec, i, &node);
		if (serialize_node(result, node))
		{
			o_disposable_dispose((t_o_disposable *)result);
			return (NULL);
		}
	}
	return (result);
}
