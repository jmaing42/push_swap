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

#include "ds_vector.h"

bool	ps_stream_internal_node_vec_remove(
	t_ds_vector *self,
	t_ps_stream_internal_command command
)
{
	t_ps_stream_internal_command_node	node;

	if (!self->v->peek(self, &node)
		|| node.command != command)
		return (false);
	if (node.count == 1)
	{
		self->v->pop(self, &node);
		return (false);
	}
	node.count--;
	self->v->set(self, self->v->length(self) - 1, &node);
	return (false);
}
