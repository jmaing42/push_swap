/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dijkstra_state_operation_rrr.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:25:28 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/30 13:20:49 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dijkstra.h"

#include <stdlib.h>

#include "ft_malloc.h"
#include "ft_memory.h"

bool	push_swap_dijkstra_state_can_rrr(
	t_push_swap_dijkstra_state *self,
	uint8_t length
)
{
	return (
		push_swap_dijkstra_state_can_rra(self, length)
		&& push_swap_dijkstra_state_can_rrb(self, length)
	);
}

void	push_swap_dijkstra_state_do_rrr(
	t_push_swap_dijkstra_state *self,
	uint8_t len,
	t_push_swap_dijkstra_state *out
)
{
	out->size_left = self->size_left;
	out->values[0] = self->values[out->size_left - 1];
	ft_memcpy(
		out->values + 1,
		self->values,
		sizeof(uint8_t) * (out->size_left - 1));
	out->values[out->size_left] = self->values[len - 1];
	ft_memcpy(
		out->values + self->size_left + 1,
		self->values + self->size_left,
		sizeof(uint8_t) * (len - self->size_left - 1));
}
