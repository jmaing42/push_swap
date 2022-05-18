/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_max_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:39:59 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/18 13:20:00 by Juyeong Maing    ###   ########.fr       */
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
	uintmax_t	result;
	uintmax_t	current;

	result = UINTMAX_MAX;
	i = -1;
	while (++i <= count)
	{
		j = -1;
		while (i + ++j <= count)
		{
			k = count - (i + j);
			current = 2 * i + 2 * j + 4 * k
				+ map[i + j].part_top + map[k].part_bottom;
			if (current < result)
				result = current;
		}
	}
	map[count].solution = result;
}

static void	bake_part_top(t_push_swap_max_count *map, size_t count)
{
	uintmax_t	i;
	uintmax_t	j;
	uintmax_t	k;
	uintmax_t	result;
	uintmax_t	current;

	result = UINTMAX_MAX;
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
				+ map[j].part_top + map[i + k].part_bottom;
			if (current < result)
				result = current;
		}
	}
	map[count].part_top = result;
}

static void	bake_part_bottom(t_push_swap_max_count *map, size_t count)
{
	uintmax_t	i;
	uintmax_t	j;
	uintmax_t	k;
	uintmax_t	result;
	uintmax_t	current;

	result = UINTMAX_MAX;
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
				+ map[i + j].part_top + map[k].part_bottom;
			if (current < result)
				result = current;
		}
	}
	map[count].part_bottom = result;
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
		bake_part_top(inout, index);
		bake_part_bottom(inout, index);
		index++;
	}
	index = in_solution_length;
	if (index < 3)
		index = 3;
	while (index < out_length)
	{
		bake_solution(inout, index);
		index++;
	}
}
