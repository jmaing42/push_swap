/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_count.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:44:12 by jmaing            #+#    #+#             */
/*   Updated: 2022/06/25 21:23:33 by Juyeong Maing    ###   ########.fr       */
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
	t_push_swap_count_item	sort_only_quick;
	t_push_swap_count_item	sort_only_merge;
	t_push_swap_count_item	sort_and_move_quick;
	t_push_swap_count_item	sort_and_move_merge;
}	t_push_swap_count_part;

t_push_swap_count_part	push_swap_count_bake_part(
							t_push_swap_count_part *map,
							size_t count);
size_t					push_swap_count_bake_part_sort_only_quick(
							const t_push_swap_count_part *map,
							size_t x,
							size_t y,
							size_t z);
size_t					push_swap_count_bake_part_sort_only_merge(
							const t_push_swap_count_part *map,
							size_t x,
							size_t y,
							size_t z);
size_t					push_swap_count_bake_part_sort_and_move_quick(
							const t_push_swap_count_part *map,
							size_t x,
							size_t y,
							size_t z);
size_t					push_swap_count_bake_part_sort_and_move_merge(
							const t_push_swap_count_part *map,
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
