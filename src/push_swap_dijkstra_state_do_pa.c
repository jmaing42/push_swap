/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dijkstra_state_do_pa.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:25:28 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/19 02:24:47 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dijkstra.h"

#include <stdlib.h>

#include "ft_malloc.h"
#include "ft_memory.h"

t_push_swap_dijkstra_state	*push_swap_dijkstra_state_do_pa(
	t_push_swap_dijkstra_state *s,
	uint8_t len
)
{
	t_push_swap_dijkstra_state *const	result = (t_push_swap_dijkstra_state *)
		ft_malloc(sizeof(t_push_swap_dijkstra_state) + sizeof(uint8_t) * len);

	result->size_left = s->size_left + 1;
	result->values[0] = s->values[s->size_left];
	ft_memcpy(
		result->values + 1,
		s->values,
		sizeof(uint8_t) * s->size_left);
	ft_memcpy(
		result->values + result->size_left,
		s->values + result->size_left,
		sizeof(uint8_t) * (len - result->size_left));
	return (result);
}
