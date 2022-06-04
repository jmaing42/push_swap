/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_count.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:44:12 by jmaing            #+#    #+#             */
/*   Updated: 2022/06/04 18:37:20 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_COUNT_H
# define PUSH_SWAP_COUNT_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_push_swap_count_item
{
	size_t	total_moves;
	size_t	x;
	size_t	y;
	size_t	z;
}	t_push_swap_count_item;

typedef struct s_push_swap_count_part
{
	t_push_swap_count_item	sort_only_divide_first;
	t_push_swap_count_item	sort_only_collect_last;
	t_push_swap_count_item	sort_and_move_divide_first;
	t_push_swap_count_item	sort_and_move_collect_last;
}	t_push_swap_count_part;

t_push_swap_count_part	push_swap_c_bake_part(
							t_push_swap_count_part *map,
							size_t count);
t_push_swap_count_item	push_swap_c_bake_part_only_first(
							t_push_swap_count_part *map,
							size_t count);
size_t					push_swap_c_bake_part_only_first_internal(
							t_push_swap_count_part *map,
							size_t x,
							size_t y,
							size_t z);
t_push_swap_count_item	push_swap_c_bake_part_only_last(
							t_push_swap_count_part *map,
							size_t count);
size_t					push_swap_c_bake_part_only_last_internal(
							t_push_swap_count_part *map,
							size_t x,
							size_t y,
							size_t z);
t_push_swap_count_item	push_swap_c_bake_part_move_first(
							t_push_swap_count_part *map,
							size_t count);
size_t					push_swap_c_bake_part_move_first_internal(
							t_push_swap_count_part *map,
							size_t x,
							size_t y,
							size_t z);
t_push_swap_count_item	push_swap_c_bake_part_move_last(
							t_push_swap_count_part *map,
							size_t count);
size_t					push_swap_c_bake_part_move_last_internal(
							t_push_swap_count_part *map,
							size_t x,
							size_t y,
							size_t z);

t_push_swap_count_item	push_swap_count_solution(
							t_push_swap_count_part *map,
							size_t count);
size_t					push_swap_count_solution_internal(
							t_push_swap_count_part *map,
							size_t x,
							size_t y,
							size_t z);

#endif
