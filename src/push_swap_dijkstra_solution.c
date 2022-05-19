/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dijkstra_solution.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 02:31:31 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/20 03:00:13 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dijkstra_internal.h"

#include <stdlib.h>

#include "ft_exit.h"

t_ft_simple_map_static	*push_swap_dijkstra_solution(uint8_t length)
{
	t_ft_simple_map_static *const		map = new_ft_simple_map_static(
			sizeof(t_push_swap_dijkstra_state)
			+ sizeof(uint8_t) * length);
	t_push_swap_dijkstra_state *const	state
		= push_swap_dijkstra_state_new(length);
	size_t								i;

	if (!map)
		ft_exit(EXIT_FAILURE);
	state->size_left = length;
	i = 0;
	while (i < length)
	{
		state->values[i] = i + 1;
		i++;
	}
	if (ft_simple_map_static_set(map, state, push_swap_operations_new()))
		ft_exit(EXIT_FAILURE);
	push_swap_dijkstra_common(map, state, length);
	return (push_swap_dijkstra_finalize(map, length));
}

t_ft_simple_map_static	*push_swap_dijkstra_solution_top(uint8_t length)
{
	t_ft_simple_map_static *const		map = new_ft_simple_map_static(
			sizeof(t_push_swap_dijkstra_state)
			+ sizeof(uint8_t) * (length + 2));
	t_push_swap_dijkstra_state *const	state
		= push_swap_dijkstra_state_new(length);
	size_t								i;

	if (!map)
		ft_exit(EXIT_FAILURE);
	state->size_left = length + 1;
	i = 0;
	while (i < length)
	{
		state->values[i] = i + 1;
		i++;
	}
	state->values[length] = 0;
	state->values[length + 1] = 0;
	if (ft_simple_map_static_set(map, state, push_swap_operations_new()))
		ft_exit(EXIT_FAILURE);
	push_swap_dijkstra_common(map, state, length + 2);
	return (push_swap_dijkstra_finalize_top(map, length));
}

t_ft_simple_map_static	*push_swap_dijkstra_solution_bottom(uint8_t length)
{
	t_ft_simple_map_static *const		map = new_ft_simple_map_static(
			sizeof(t_push_swap_dijkstra_state)
			+ sizeof(uint8_t) * (length + 2));
	t_push_swap_dijkstra_state *const	state
		= push_swap_dijkstra_state_new(length);
	size_t								i;

	if (!map)
		ft_exit(EXIT_FAILURE);
	state->size_left = length + 1;
	i = 0;
	state->values[0] = 0;
	while (i < length)
	{
		state->values[i + 1] = i + 1;
		i++;
	}
	state->values[length + 1] = 0;
	if (ft_simple_map_static_set(map, state, push_swap_operations_new()))
		ft_exit(EXIT_FAILURE);
	push_swap_dijkstra_common(map, state, length + 2);
	return (push_swap_dijkstra_finalize_top(map, length));
}
