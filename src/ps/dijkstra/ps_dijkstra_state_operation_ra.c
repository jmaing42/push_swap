/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_dijkstra_state_operation_ra.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:25:28 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/01 00:17:13 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_dijkstra.h"

#include <stdlib.h>

#include "ft_malloc.h"
#include "ft_memory.h"

bool	ps_dijkstra_state_can_ra(
	t_ps_dijkstra_state *self,
	uint8_t length
)
{
	(void)length;
	return (
		self->size_left >= 2
		&& self->values[0]
	);
}

void	ps_dijkstra_state_do_ra(
	t_ps_dijkstra_state *self,
	uint8_t len,
	t_ps_dijkstra_state *out
)
{
	out->size_left = self->size_left;
	ft_memcpy(
		out->values,
		self->values + 1,
		sizeof(uint8_t) * (out->size_left - 1));
	out->values[out->size_left - 1] = self->values[0];
	ft_memcpy(
		out->values + self->size_left,
		self->values + self->size_left,
		sizeof(uint8_t) * (len - self->size_left));
}
