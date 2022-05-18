/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_max_count.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:39:59 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/18 13:23:15 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_MAX_COUNT_H
# define PUSH_SWAP_MAX_COUNT_H

# include <stddef.h>
# include <stdint.h>

typedef struct s_push_swap_max_count
{
	uintmax_t	solution;
	uintmax_t	part_top;
	uintmax_t	part_bottom;
	size_t		solution_a_top;
	size_t		solution_b_top;
	size_t		solution_b_bottom;
	size_t		part_top_self_bottom;
	size_t		part_top_other_top;
	size_t		part_top_other_bottom;
	size_t		part_bottom_self_top;
	size_t		part_bottom_other_top;
	size_t		part_bottom_other_bottom;
}	t_push_swap_max_count;

void	push_swap_max_count(
			t_push_swap_max_count *inout,
			size_t out_length,
			size_t in_solution_length,
			size_t in_part_length);

#endif
