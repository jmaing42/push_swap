/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dijkstra_state_bottom.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:25:28 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/19 02:43:23 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dijkstra.h"

#include <stdlib.h>

#include "ft_malloc.h"

t_push_swap_dijkstra_state	*push_swap_dijkstra_state_bottom(
	uint8_t l
)
{
	t_push_swap_dijkstra_state *const	result = (t_push_swap_dijkstra_state *)
		ft_malloc(sizeof(t_push_swap_dijkstra_state) + sizeof(uint8_t) * l + 2);
	size_t								i;

	result->size_left = l + 1;
	i = 0;
	while (i < l)
	{
		result->values[i + 1] = i + 1;
		i++;
	}
	result->values[0] = 0;
	result->values[l + 1] = 0;
	return (result);
}