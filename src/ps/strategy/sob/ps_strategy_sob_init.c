/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_sob_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:15:44 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 17:44:25 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_sob.h"

#include <stdint.h>

#include "ps_strategy_sob_merge_twist_up.h"
// #include "ps_strategy_sob_merge_twist_down.h"
// #include "ps_strategy_sob_merge_straightforward.h"
// #include "ps_strategy_sob_merge_rotate_up.h"
// #include "ps_strategy_sob_merge_rotate_down.h"
// #include "ps_strategy_sob_quick_twist.h"
// #include "ps_strategy_sob_quick_straightforward.h"

void	ps_strategy_sob_init(
	t_ps_strategy_count *table,
	size_t index
)
{
	table[index].sob.item.moves = table[index].tob.item.moves;
	table[index].sob.func = ps_strategy_sob_fallback_tob_execute;
	table[index].sob.name = "sob_fallback_tot";
	ps_strategy_sob_merge_twist_up_count_init_if_better(table, index);
	ps_strategy_sob_merge_twist_down_count_init_if_better(table, index);
	ps_strategy_sob_merge_straightforward_count_init_if_better(table, index);
	ps_strategy_sob_merge_rotate_up_count_init_if_better(table, index);
	ps_strategy_sob_merge_rotate_down_count_init_if_better(table, index);
	ps_strategy_sob_quick_twist_count_init_if_better(table, index);
	ps_strategy_sob_quick_straightforward_count_init_if_better(table, index);
}
