/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dijkstra_state_operation_pa.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:25:28 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/30 13:16:25 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dijkstra.h"

#include <stdlib.h>

#include "ft_malloc.h"
#include "ft_memory.h"

bool	push_swap_dijkstra_state_can_pa(
	t_push_swap_dijkstra_state *self,
	uint8_t length
)
{
	return (
		length - self->size_left
		&& self->values[self->size_left]
	);
}

void	push_swap_dijkstra_state_do_pa(
	t_push_swap_dijkstra_state *s,
	uint8_t len,
	t_push_swap_dijkstra_state *out
)
{
	out->size_left = s->size_left + 1;
	out->values[0] = s->values[s->size_left];
	ft_memcpy(
		out->values + 1,
		s->values,
		sizeof(uint8_t) * s->size_left);
	ft_memcpy(
		out->values + out->size_left,
		s->values + out->size_left,
		sizeof(uint8_t) * (len - out->size_left));
}
