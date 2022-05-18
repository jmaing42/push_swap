/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_max_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:39:59 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/18 17:14:51 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_max_count.h"

static void	bake_part_top(t_push_swap_max_count *map, size_t count);
static void	bake_part_bottom(t_push_swap_max_count *map, size_t count);

static void	bake_solution(t_push_swap_max_count *map, size_t count)
{
	uintmax_t	i;
	uintmax_t	j;
	uintmax_t	k;
	uintmax_t	current;

	i = -1;
	while (++i <= count)
	{
		j = -1;
		while (i + ++j <= count)
		{
			k = count - (i + j);
			current = 2 * i + 2 * j + 4 * k
				+ map[i].part_top + map[j].part_top + map[k].part_bottom;
			if (current < map[count].solution)
			{
				map[count].solution = current;
				map[count].solution_a_top = i;
				map[count].solution_b_top = j;
				map[count].solution_b_bottom = k;
			}
		}
	}
}

static void	bake_part_top(t_push_swap_max_count *map, size_t count)
{
	uintmax_t	i;
	uintmax_t	j;
	uintmax_t	k;
	uintmax_t	current;

	i = -1;
	while (++i < count)
	{
		j = -1;
		while (i + ++j <= count)
		{
			k = count - (i + j);
			if (j == count || k == count)
				continue ;
			current = 2 * i + 2 * j + 4 * k
				+ map[i].part_bottom + map[j].part_top + map[k].part_bottom;
			if (current < map[count].part_top)
			{
				map[count].part_top = current;
				map[count].part_top_self_bottom = i;
				map[count].part_top_other_top = j;
				map[count].part_top_other_bottom = k;
			}
		}
	}
}

static void	bake_part_bottom(t_push_swap_max_count *map, size_t count)
{
	uintmax_t	i;
	uintmax_t	j;
	uintmax_t	k;
	uintmax_t	current;

	i = -1;
	while (++i < count)
	{
		j = -1;
		while (i + ++j <= count)
		{
			k = count - (i + j);
			if (j == count || k == count)
				continue ;
			current = 2 * i + 4 * j + 6 * k
				+ map[i].part_top + map[j].part_top + map[k].part_bottom;
			if (current < map[count].part_bottom)
			{
				map[count].part_bottom = current;
				map[count].part_bottom_self_top = i;
				map[count].part_bottom_other_top = j;
				map[count].part_bottom_other_bottom = k;
			}
		}
	}
}

static void	defaults(
	t_push_swap_max_count *inout,
	size_t out_length,
	size_t in_solution_length,
	size_t in_part_length
)
{
	if (in_part_length <= 0 && 0 < out_length)
	{
		inout[0].part_top = 0;
		inout[0].part_bottom = 0;
	}
	if (in_part_length <= 1 && 1 < out_length)
	{
		inout[1].part_top = 0;
		inout[1].part_bottom = 0;
	}
	if (in_part_length <= 2 && 2 < out_length)
	{
		inout[2].part_top = 1;
		inout[2].part_bottom = 5;
	}
	if (in_solution_length <= 0 && 0 < out_length)
		inout[0].solution = 0;
	if (in_solution_length <= 1 && 1 < out_length)
		inout[1].solution = 0;
	if (in_solution_length <= 2 && 2 < out_length)
		inout[2].solution = 1;
}

void	push_swap_max_count(
	t_push_swap_max_count *inout,
	size_t out_length,
	size_t in_solution_length,
	size_t in_part_length
)
{
	size_t	index;

	defaults(inout, out_length, in_solution_length, in_part_length);
	index = in_part_length;
	if (index < 3)
		index = 3;
	while (index < out_length)
	{
		inout[index].part_top = UINTMAX_MAX;
		bake_part_top(inout, index);
		inout[index].part_bottom = UINTMAX_MAX;
		bake_part_bottom(inout, index);
		index++;
	}
	index = in_solution_length;
	if (index < 3)
		index = 3;
	while (index < out_length)
	{
		inout[index].solution = UINTMAX_MAX;
		bake_solution(inout, index);
		index++;
	}
}
