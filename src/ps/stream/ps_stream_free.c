/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 23:41:43 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/07 23:47:49 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream.h"

#include <stdlib.h>

static void	free_node(t_ps_stream_node *node)
{
	t_ps_stream_node_parallel *const	n = node;
	t_ps_stream_node_parallel_list_node	*subnode;

	if (*((t_ps_stream_node_type *) node) == PS_STREAM_NODE_TYPE_SEPARATOR)
	{
		free(node);
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
	free(node);
}

void	ps_stream_free(
	t_ps_stream *self
)
{
	//
}
