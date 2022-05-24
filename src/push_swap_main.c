/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:41:01 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/25 02:35:56 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>

#include "ft_malloc.h"
#include "ft_io.h"
#include "push_swap_count.h"
#include "push_swap_dijkstra.h"

#define TEST_SIZE 1000

void	push_swap_dijkstra_common(
	t_ft_simple_map_static *map,
	t_push_swap_dijkstra_state *initial_state,
	uint8_t length
)
{
	(void)map;
	(void)initial_state;
	(void)length;
}

t_ft_simple_map_static	*push_swap_dijkstra_finalize(
	t_ft_simple_map_static *map,
	uint8_t length
)
{
	(void)map;
	(void)length;
}

t_ft_simple_map_static	*push_swap_dijkstra_finalize_top(
	t_ft_simple_map_static *map,
	uint8_t length
)
{
	(void)map;
	(void)length;
}

t_ft_simple_map_static	*push_swap_dijkstra_finalize_bottom(
	t_ft_simple_map_static *map,
	uint8_t length
)
{
	(void)map;
	(void)length;
}

static void	count_internal(t_push_swap_count_part *map)
{
	map[0].sort_only_divide_first = (t_push_swap_count_item){0, 0, 0, 0};
	map[0].sort_only_collect_last = (t_push_swap_count_item){0, 0, 0, 0};
	map[0].sort_and_move_divide_first = (t_push_swap_count_item){0, 0, 0, 0};
	map[0].sort_and_move_collect_last = (t_push_swap_count_item){0, 0, 0, 0};
	map[1].sort_only_divide_first = (t_push_swap_count_item){0, 0, 0, 0};
	map[1].sort_only_collect_last = (t_push_swap_count_item){0, 0, 0, 0};
	map[1].sort_and_move_divide_first = (t_push_swap_count_item){1, 0, 0, 0};
	map[1].sort_and_move_collect_last = (t_push_swap_count_item){1, 0, 0, 0};
	map[2].sort_only_divide_first = (t_push_swap_count_item){1, 0, 0, 0};
	map[2].sort_only_collect_last = (t_push_swap_count_item){1, 0, 0, 0};
	map[2].sort_and_move_divide_first = (t_push_swap_count_item){3, 0, 0, 0};
	map[2].sort_and_move_collect_last = (t_push_swap_count_item){3, 0, 0, 0};
}

static void	count(size_t index)
{
	t_push_swap_count_part *const	map = (t_push_swap_count_part *)
		ft_malloc(sizeof(t_push_swap_count_part) * index + 1);
	size_t							i;

	count_internal(map);
	i = 2;
	while (++i <= index)
		map[i] = push_swap_count_bake_part(map, i);
	i = -1;
	while (++i <= index)
		printf("%zu: %zu(%zu, %zu, %zu) %zu(%zu, %zu, %zu) %zu(%zu, %zu, %zu) %zu(%zu, %zu, %zu) - %s %s\n", i,
			map[i].sort_only_divide_first.total_moves,
			map[i].sort_only_divide_first.x,
			map[i].sort_only_divide_first.y,
			map[i].sort_only_divide_first.z,
			map[i].sort_only_collect_last.total_moves,
			map[i].sort_only_collect_last.x,
			map[i].sort_only_collect_last.y,
			map[i].sort_only_collect_last.z,
			map[i].sort_and_move_divide_first.total_moves,
			map[i].sort_and_move_divide_first.x,
			map[i].sort_and_move_divide_first.y,
			map[i].sort_and_move_divide_first.z,
			map[i].sort_and_move_collect_last.total_moves,
			map[i].sort_and_move_collect_last.x,
			map[i].sort_and_move_collect_last.y,
			map[i].sort_and_move_collect_last.z,
			map[i].sort_only_divide_first.total_moves > map[i].sort_only_collect_last.total_moves ? "true" : "false",
			map[i].sort_and_move_divide_first.total_moves > map[i].sort_and_move_collect_last.total_moves ? "true" : "false");
	i = -1;
	while (++i <= index)
		printf("%zu - solution = %zu\n", i, push_swap_count_solution(map, i).total_moves);
	free(map);
}

int	main(int argc, char **argv, char **envp)
{
	t_push_swap	context;

	count(1000);
	// if (push_swap_init(&context, argc, argv, envp))
	// 	return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
