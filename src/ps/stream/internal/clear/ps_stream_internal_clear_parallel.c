/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_clear_parallel.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:45:29 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/20 20:41:33 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

#include "ft_primitive_size_t.h"

static void	ps_stream_internal_clear_parallel_swap(
	t_ps_stream_node_parallel_list_node *node
)
{
	node->count %= 2;
}

static void	ps_stream_internal_clear_parallel_rr_r(
	t_ps_stream_node_parallel_list_node *second_last,
	t_ps_stream_node_parallel_list_node *last
)
{
	const size_t	common
		= ft_primitive_size_t_min(second_last->count, last->count);

	second_last->count -= common;
	last->count -= common;
}

static void	ps_stream_internal_clear_parallel_r_rr(
	t_ps_stream_node_parallel_list_node *second_last,
	t_ps_stream_node_parallel_list_node *last
)
{
	const size_t	common
		= ft_primitive_size_t_min(second_last->count, last->count);

	second_last->count -= common;
	last->count -= common;
}

void	ps_stream_internal_clear_parallel(
	t_ps_stream_node_parallel_list *list
)
{
	if (!list->tail)
		return ;
	if (list->tail->type == PS_STREAM_NODE_PARALLEL_OPERATION_SWAP)
		ps_stream_internal_clear_parallel_swap(list->tail);
	else if (
		list->tail->type
		== PS_STREAM_NODE_PARALLEL_OPERATION_ROTATE
		&& list->tail->prev
		&& list->tail->prev->type
		== PS_STREAM_NODE_PARALLEL_OPERATION_REVERSE_ROTATE)
		ps_stream_internal_clear_parallel_rr_r(
			list->tail->prev,
			list->tail);
	else if (
		list->tail->type
		== PS_STREAM_NODE_PARALLEL_OPERATION_REVERSE_ROTATE
		&& list->tail->prev
		&& list->tail->prev->type
		== PS_STREAM_NODE_PARALLEL_OPERATION_ROTATE)
		ps_stream_internal_clear_parallel_r_rr(
			list->tail->prev,
			list->tail);
	ps_stream_internal_clear_parallel_remove_zeros(list);
}
