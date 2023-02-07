/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:15:45 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/18 00:15:45 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream.h"

#include <stdlib.h>

static void	ps_stream_free_parallel_list(
	t_ps_stream_node_parallel_list *list
)
{
	t_ps_stream_node_parallel_list_node	*current;
	t_ps_stream_node_parallel_list_node	*to_remove;

	current = list->head;
	while (current)
	{
		to_remove = current;
		current = current->next;
		free(to_remove);
	}
}

static void	ps_stream_free_node(
	t_ps_stream_node *node
)
{
	if (*node->value.type == PS_STREAM_NODE_TYPE_PARALLEL)
	{
		ps_stream_free_parallel_list(&node->value.parallel->a);
		ps_stream_free_parallel_list(&node->value.parallel->b);
	}
	free(node);
}

void	ps_stream_free(
	t_ps_stream *self
)
{
	t_ps_stream_node	*current;
	t_ps_stream_node	*to_remove;

	current = self->head;
	while (current)
	{
		to_remove = current;
		current = current->next;
		ps_stream_free_node(to_remove);
	}
}
