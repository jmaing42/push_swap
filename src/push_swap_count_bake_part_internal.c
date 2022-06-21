/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_count_bake_part_internal.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:52:28 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/22 01:47:16 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_count.h"

#include <stdint.h>

#include "ft_size_t.h"

static inline size_t	_(const char *comment)
{
	(void)comment;
	return (0);
}

size_t	push_swap_c_bake_part_only_first_internal(
	t_push_swap_count_part *map,
	size_t x,
	size_t y,
	size_t z
)
{
	_("|   :     |         |         |         |         |   X     ||  x/y/z ");
	_("|   :     |         |         |   y     |   Y     |   Y     ||  X/Y/Z ");
	_("|   :     |     z   |   Z     |   Z x   |   Z x   |   Z     ||        ");
	_("| --A-B-- | --A-B-- | --A-B-- | --A-B-- | --A-B-- | --A-B-- || upper  ");
	_("|         |   y x   |   y x   |         |         |         ||  case  ");
	_("|       (1)       (2)       (3)       (4)       (5)         ||   is   ");
	_("|  divide    sort+move z    rotate    sort y    sort+move x || sorted ");
	return (
		+ 2 * x + y + z + _("                                       divide (1)")
		+ ft_size_t_min(_("                                    sort+move z (2)")
			+ map[z].sort_and_move_collect_last.total_moves,
			+ map[z].sort_and_move_divide_first.total_moves
		)
		+ ft_size_t_max(y, x) + _("                                 rotate (3)")
		+ ft_size_t_min(_("                                         sort y (4)")
			+ map[y].sort_only_collect_last.total_moves,
			+ map[y].sort_only_divide_first.total_moves
		)
		+ ft_size_t_min(_("                                    sort+move x (5)")
			+ map[x].sort_and_move_collect_last.total_moves,
			+ map[x].sort_and_move_divide_first.total_moves
		)
	);
}

size_t	push_swap_c_bake_part_only_last_internal(
	t_push_swap_count_part *map,
	size_t x,
	size_t y,
	size_t z
)
{
	_("|   x     |         |         |         |         |   :     ||  x/y/z ");
	_("|   y     |   y     |     Y   |     Y   |         |   :     ||  X/Y/Z ");
	_("|   z     |   z X   |   z X   |   Z X   |     X   |   :     ||        ");
	_("| --A-B-- | --A-B-- | --A-B-- | --A-B-- | --A-B-- | --A-B-- || upper  ");
	_("|         |         |         |         |   Z Y   |         ||  case  ");
	_("|         (1)       (2)       (3)       (4)       (5)       ||   is   ");
	_("| sort+move x    sort+move y    sort z    rotate    collect || sorted ");
	return (
		+ ft_size_t_min(_("                                    sort+move x (1)")
			+ map[x].sort_and_move_collect_last.total_moves,
			+ map[x].sort_and_move_divide_first.total_moves
		)
		+ ft_size_t_min(_("                                    sort+move y (2)")
			+ map[y].sort_and_move_collect_last.total_moves,
			+ map[y].sort_and_move_divide_first.total_moves
		)
		+ ft_size_t_min(_("                                         sort z (3)")
			+ map[z].sort_only_collect_last.total_moves,
			+ map[z].sort_only_divide_first.total_moves
		)
		+ ft_size_t_max(z, y) + _("                                 rotate (4)")
		+ x + 2 * y + z + _("                                      collect (5)")
	);
}

size_t	push_swap_c_bake_part_move_first_internal(
	t_push_swap_count_part *map,
	size_t x,
	size_t y,
	size_t z
)
{
	_("|   :     |         |         |         |         |     X   ||  x/y/z ");
	_("|   :     |         |         |     y   |     Y   |     Y   ||  X/Y/Z ");
	_("|   :     |     z   |     Z   |   x Z   |   x Z   |     Z   ||        ");
	_("| --A-B-- | --A-B-- | --A-B-- | --A-B-- | --A-B-- | --A-B-- || upper  ");
	_("|         |   x y   |   x y   |         |         |         ||  case  ");
	_("|       (1)       (2)       (3)       (4)       (5)         ||   is   ");
	_("|  divide    sort z    rotate    sort+move y    sort+move x || sorted ");
	return (
		+ x + 2 * y + z + _("                                       divide (1)")
		+ ft_size_t_min(_("                                         sort z (2)")
			+ map[x].sort_only_collect_last.total_moves,
			+ map[x].sort_only_divide_first.total_moves
		)
		+ ft_size_t_max(x, y) + _("                                 rotate (3)")
		+ ft_size_t_min(_("                                    sort+move y (4)")
			+ map[y].sort_and_move_collect_last.total_moves,
			+ map[y].sort_and_move_divide_first.total_moves
		)
		+ ft_size_t_min(_("                                    sort+move x (5)")
			+ map[x].sort_and_move_collect_last.total_moves,
			+ map[x].sort_and_move_divide_first.total_moves
		)
	);
}

size_t	push_swap_c_bake_part_move_last_internal(
	t_push_swap_count_part *map,
	size_t x,
	size_t y,
	size_t z
)
{
	_("|   x     |         |         |         |         |     :   ||  x/y/z ");
	_("|   y     |   y     |   Y     |         |         |     :   ||  X/Y/Z ");
	_("|   z     |   z X   |   z X   |   z     |   Z     |     :   ||        ");
	_("| --A-B-- | --A-B-- | --A-B-- | --A-B-- | --A-B-- | --A-B-- || upper  ");
	_("|         |         |         |   Y X   |   Y Z   |         ||  case  ");
	_("|         (1)       (2)       (3)       (4)       (5)       ||   is   ");
	_("|  sort+move x     sort y     rotate     sort z     collect || sorted ");
	return (
		+ ft_size_t_min(_("                                    sort+move x (1)")
			+ map[x].sort_and_move_collect_last.total_moves,
			+ map[x].sort_and_move_divide_first.total_moves
		)
		+ ft_size_t_min(_("                                         sort y (2)")
			+ map[y].sort_only_collect_last.total_moves,
			+ map[y].sort_only_divide_first.total_moves
		)
		+ ft_size_t_max(y, x) + _("                                 rotate (3)")
		+ ft_size_t_min(_("                                         sort z (4)")
			+ map[z].sort_only_collect_last.total_moves,
			+ map[z].sort_only_divide_first.total_moves
		)
		+ x + 2 * y + z + _("                                      collect (5)")
	);
}
