/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_node_vec_append.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/02/18 00:40:45 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

#include "ft_types.h"
#include "ds_vector.h"

t_err	ps_stream_internal_node_vec_append(
	t_ds_vector *self,
	t_ps_stream_internal_command command
)
{
	t_ps_stream_internal_command_node	node;

	if (self->v->peek(self, &node) && node.command == command)
	{
		node.count++;
		self->v->set(self, self->v->length(self) - 1, &node);
		return (false);
	}
	node.command = command;
	node.count = 1;
	if (self->v->push(self, &node))
		return (true);
	return (false);
}
