/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dijkstra_state_operation_ss.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:25:28 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/30 13:22:55 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dijkstra.h"

#include <stdlib.h>

#include "ft_malloc.h"
#include "ft_memory.h"

bool	push_swap_dijkstra_state_can_ss(
	t_push_swap_dijkstra_state *self,
	uint8_t length
)
{
	return (
		push_swap_dijkstra_state_can_sa(self, length)
		&& push_swap_dijkstra_state_can_sb(self, length)
	);
}

void	push_swap_dijkstra_state_do_ss(
	t_push_swap_dijkstra_state *self,
	uint8_t len,
	t_push_swap_dijkstra_state *out
)
{
	out->size_left = self->size_left;
	ft_memcpy(out->values, self->values, sizeof(uint8_t) * len);
	out->values[0] = self->values[1];
	out->values[1] = self->values[0];
	out->values[self->size_left] = self->values[self->size_left + 1];
	out->values[self->size_left + 1] = self->values[self->size_left];
}
