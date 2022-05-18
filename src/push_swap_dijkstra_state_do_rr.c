/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dijkstra_state_do_rr.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:25:28 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/19 02:36:28 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dijkstra.h"

#include <stdlib.h>

#include "ft_malloc.h"
#include "ft_memory.h"

t_push_swap_dijkstra_state	*push_swap_dijkstra_state_do_rr(
	t_push_swap_dijkstra_state *self,
	uint8_t len
)
{
	t_push_swap_dijkstra_state *const	result = (t_push_swap_dijkstra_state *)
		ft_malloc(sizeof(t_push_swap_dijkstra_state) + sizeof(uint8_t) * len);

	result->size_left = self->size_left;
	ft_memcpy(
		result->values,
		self->values + 1,
		sizeof(uint8_t) * (result->size_left - 1));
	result->values[result->size_left - 1] = self->values[0];
	ft_memcpy(
		result->values + self->size_left,
		self->values + self->size_left + 1,
		sizeof(uint8_t) * (len - self->size_left - 1));
	result->values[len - 1] = self->values[self->size_left];
	return (result);
}
