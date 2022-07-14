/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_make_last_parallel_node_rotate. :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:45:09 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/14 23:45:10 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

#include <stdlib.h>

t_err	ps_stream_internal_make_last_parallel_node_rotate(
	t_ps_stream_node_parallel_list *list
)
{
	t_ps_stream_node_parallel_list_node	*node;

	if (
		list->tail
		&& list->tail->type == PS_STREAM_NODE_PARALLEL_OPERATION_ROTATE
	)
		return (false);
	node = malloc(sizeof(t_ps_stream_node_parallel_list_node));
	if (!node)
		return (true);
	node->next = NULL;
	node->prev = list->tail;
	node->type = PS_STREAM_NODE_PARALLEL_OPERATION_ROTATE;
	node->count = 0;
	if (list->tail)
		list->tail->next = node;
	else
		list->head = node;
	list->tail = node;
	return (false);
}
