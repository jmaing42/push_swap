/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 09:54:40 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/10 09:54:41 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_main.h"

void	push_swap_main_init_012(t_push_swap *self, unsigned int count)
{
	t_push_swap_count_part *const	map = self->map;

	map[0].sort_only_quick = (t_push_swap_count_item){0, 0, 0, 0};
	map[0].sort_only_merge = (t_push_swap_count_item){0, 0, 0, 0};
	map[0].sort_and_move_quick = (t_push_swap_count_item){0, 0, 0, 0};
	map[0].sort_and_move_merge = (t_push_swap_count_item){0, 0, 0, 0};
	if (count < 1)
		return ;
	map[1].sort_only_quick = (t_push_swap_count_item){0, 0, 0, 0};
	map[1].sort_only_merge = (t_push_swap_count_item){0, 0, 0, 0};
	map[1].sort_and_move_quick = (t_push_swap_count_item){1, 0, 0, 0};
	map[1].sort_and_move_merge = (t_push_swap_count_item){1, 0, 0, 0};
	if (count < 2)
		return ;
	map[2].sort_only_quick = (t_push_swap_count_item){1, 0, 0, 0};
	map[2].sort_only_merge = (t_push_swap_count_item){1, 0, 0, 0};
	map[2].sort_and_move_quick = (t_push_swap_count_item){3, 0, 0, 0};
	map[2].sort_and_move_merge = (t_push_swap_count_item){3, 0, 0, 0};
}

void	push_swap_main_init_345(t_push_swap *self, unsigned int count)
{
	t_push_swap_count_part *const	map = self->map;

	if (count < 3)
		return ;
	map[3].sort_only_quick = (t_push_swap_count_item){5, 0, 0, 0};
	map[3].sort_only_merge = (t_push_swap_count_item){5, 0, 0, 0};
	map[3].sort_and_move_quick = (t_push_swap_count_item){6, 0, 0, 0};
	map[3].sort_and_move_merge = (t_push_swap_count_item){6, 0, 0, 0};
	if (count < 4)
		return ;
	map[4].sort_only_quick = (t_push_swap_count_item){9, 0, 0, 0};
	map[4].sort_only_merge = (t_push_swap_count_item){9, 0, 0, 0};
	map[4].sort_and_move_quick = (t_push_swap_count_item){8, 0, 0, 0};
	map[4].sort_and_move_merge = (t_push_swap_count_item){8, 0, 0, 0};
	if (count < 5)
		return ;
	map[5].sort_only_quick = (t_push_swap_count_item){12, 0, 0, 0};
	map[5].sort_only_merge = (t_push_swap_count_item){12, 0, 0, 0};
	map[5].sort_and_move_quick = (t_push_swap_count_item){10, 0, 0, 0};
	map[5].sort_and_move_merge = (t_push_swap_count_item){10, 0, 0, 0};
}

void	push_swap_main_init_678(t_push_swap *self, unsigned int count)
{
	t_push_swap_count_part *const	map = self->map;

	if (count < 6)
		return ;
	map[6].sort_only_quick = (t_push_swap_count_item){15, 0, 0, 0};
	map[6].sort_only_merge = (t_push_swap_count_item){15, 0, 0, 0};
	map[6].sort_and_move_quick = (t_push_swap_count_item){13, 0, 0, 0};
	map[6].sort_and_move_merge = (t_push_swap_count_item){13, 0, 0, 0};
	if (count < 7)
		return ;
	map[7].sort_only_quick = (t_push_swap_count_item){18, 0, 0, 0};
	map[7].sort_only_merge = (t_push_swap_count_item){18, 0, 0, 0};
	map[7].sort_and_move_quick = (t_push_swap_count_item){16, 0, 0, 0};
	map[7].sort_and_move_merge = (t_push_swap_count_item){16, 0, 0, 0};
	if (count < 8)
		return ;
	map[8].sort_only_quick = (t_push_swap_count_item){21, 0, 0, 0};
	map[8].sort_only_merge = (t_push_swap_count_item){21, 0, 0, 0};
	map[8].sort_and_move_quick = (t_push_swap_count_item){19, 0, 0, 0};
	map[8].sort_and_move_merge = (t_push_swap_count_item){19, 0, 0, 0};
}
