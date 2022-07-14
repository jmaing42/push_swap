/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_make_last_node_separator.c      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:45:06 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/14 23:45:06 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

#include <stdlib.h>

t_err	ps_stream_internal_make_last_node_separator(t_ps_stream *self)
{
	t_ps_stream_node_in_separator	*node;

	if (self->tail && *self->tail->value.type == PS_STREAM_NODE_TYPE_SEPARATOR)
		return (false);
	node = malloc(sizeof(t_ps_stream_node_in_separator));
	if (!node)
		return (true);
	node->super.value.separator = &node->value;
	node->super.next = NULL;
	node->super.prev = self->tail;
	node->value.type = PS_STREAM_NODE_TYPE_SEPARATOR;
	node->value.pa = 0;
	node->value.pb = 0;
	if (self->tail)
		self->tail->next = &node->super;
	else
		self->head = &node->super;
	self->tail = &node->super;
	return (false);
}
