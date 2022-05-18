/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dijkstra_state_empty.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:25:28 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/19 01:50:17 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dijkstra.h"

#include <stdlib.h>

#include "ft_malloc.h"

t_push_swap_dijkstra_state	*push_swap_dijkstra_state_empty(
	uint8_t len
)
{
	t_push_swap_dijkstra_state *const	result = (t_push_swap_dijkstra_state *)
		ft_malloc(sizeof(t_push_swap_dijkstra_state) + sizeof(uint8_t) * len);
	size_t								i;

	result->size_left = len;
	i = 0;
	while (i < len)
	{
		result->values[i] = i + 1;
		i++;
	}
	return (result);
}
