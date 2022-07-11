/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 23:41:43 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/11 09:14:23 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream.h"

#include <stdlib.h>

static void	free_node(t_ps_stream_node *node)
{
	t_ps_stream_node_parallel *const	n = node->value.parallel;
	t_ps_stream_node_parallel_list_node	*subnode;

	if (*node->value.type == PS_STREAM_NODE_TYPE_SEPARATOR)
	{
		free(node->value.separator);
		return ;
	}
	while (n->a_head)
	{
		subnode = n->a_head->next;
		free(n->a_head);
		n->a_head = subnode;
	}
	while (n->b_head)
	{
		subnode = n->b_head->next;
		free(n->b_head);
		n->b_head = subnode;
	}
	free(n);
}

void	ps_stream_free(
	t_ps_stream *self
)
{
	t_ps_stream_node	*subnode;

	if (!self)
		return ;
	while (self->head)
	{
		subnode = self->head->next;
		free_node(self->head);
		self->head = subnode;
	}
}
