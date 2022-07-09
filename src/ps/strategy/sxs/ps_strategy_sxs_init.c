/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_sxs_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:55:41 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 16:18:14 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_sxs.h"

#include <stdint.h>

#include "ps_strategy_sxs_merge_twist_up.h"
// #include "ps_strategy_sxs_merge_twist_down.h"
// #include "ps_strategy_sxs_merge_straightforward.h"
// #include "ps_strategy_sxs_merge_rotate_up.h"
// #include "ps_strategy_sxs_merge_rotate_down.h"
// #include "ps_strategy_sxs_quick_twist.h"
// #include "ps_strategy_sxs_quick_straightforward.h"

void	ps_strategy_sss_init(
	t_ps_strategy_count *table,
	size_t index
)
{
	table[index].sxs.item.moves = table[index].tst.item.moves;
	table[index].sxs.func = ps_strategy_sxs_fallback_txt_execute;
	table[index].sxs.name = "sxs_fallback_txt";
	ps_strategy_sxs_merge_twist_up_count_init_if_better(table, index);
	// ps_strategy_sxs_merge_twist_down_count_init_if_better(table, index);
	// ps_strategy_sxs_merge_straightforward_count_init_if_better(table, index);
	// ps_strategy_sxs_merge_rotate_up_count_init_if_better(table, index);
	// ps_strategy_sxs_merge_rotate_down_count_init_if_better(table, index);
	// ps_strategy_sxs_quick_twist_count_init_if_better(table, index);
	// ps_strategy_sxs_quick_straightforward_count_init_if_better(table, index);
}
