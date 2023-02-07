/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_clear_parallel_remove_zeros.c   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:44:30 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/15 00:55:29 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

#include <stdlib.h>

static void	ps_stream_internal_clear_parallel_remove_second_last(
	t_ps_stream_node_parallel_list *list
)
{
	t_ps_stream_node_parallel_list_node *const	to_free = list->tail->prev;

	if (!to_free->prev)
		list->head = to_free->next;
	else
		to_free->prev->next = to_free->next;
	to_free->next->prev = to_free->prev;
	free(to_free);
}

static void	ps_stream_internal_clear_parallel_remove_last(
	t_ps_stream_node_parallel_list *list
)
{
	t_ps_stream_node_parallel_list_node *const	to_free = list->tail;

	if (!to_free->prev)
		list->head = to_free->next;
	else
		to_free->prev->next = to_free->next;
	list->tail = to_free->prev;
	free(to_free);
}

void	ps_stream_internal_clear_parallel_remove_zeros(
	t_ps_stream_node_parallel_list *list
)
{
	if (!list->tail)
		return ;
	if (list->tail->prev && !list->tail->prev->count)
		ps_stream_internal_clear_parallel_remove_second_last(list);
	if (!list->tail->count)
		ps_stream_internal_clear_parallel_remove_last(list);
}
