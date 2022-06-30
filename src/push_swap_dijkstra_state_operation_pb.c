/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dijkstra_state_operation_pb.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:25:28 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/30 13:17:20 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dijkstra.h"

#include <stdlib.h>

#include "ft_malloc.h"
#include "ft_memory.h"

bool	push_swap_dijkstra_state_can_pb(
	t_push_swap_dijkstra_state *self,
	uint8_t length
)
{
	(void)length;
	return (
		self->size_left
		&& self->values[0]
	);
}

void	push_swap_dijkstra_state_do_pb(
	t_push_swap_dijkstra_state *self,
	uint8_t len,
	t_push_swap_dijkstra_state *out
)
{
	out->size_left = self->size_left - 1;
	ft_memcpy(
		out->values,
		self->values + 1,
		sizeof(uint8_t) * out->size_left);
	out->values[out->size_left] = self->values[0];
	ft_memcpy(
		out->values + self->size_left,
		self->values + self->size_left,
		sizeof(uint8_t) * (len - self->size_left));
}
