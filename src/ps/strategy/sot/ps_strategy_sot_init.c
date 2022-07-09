/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_sot_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:15:44 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 17:44:13 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_sot.h"

#include <stdint.h>

#include "ps_strategy_sot_merge_twist_up.h"
// #include "ps_strategy_sot_merge_twist_down.h"
// #include "ps_strategy_sot_merge_straightforward.h"
// #include "ps_strategy_sot_merge_rotate_up.h"
// #include "ps_strategy_sot_merge_rotate_down.h"
// #include "ps_strategy_sot_quick.h"

void	ps_strategy_sot_init(
	t_ps_strategy_count *table,
	size_t index
)
{
	table[index].sot.item.moves = table[index].tot.item.moves;
	table[index].sot.func = ps_strategy_sot_fallback_tot_execute;
	table[index].sot.name = "sot_fallback_tot";
	ps_strategy_sot_merge_twist_up_count_init_if_better(table, index);
	// ps_strategy_sot_merge_twist_down_count_init_if_better(table, index);
	// ps_strategy_sot_merge_straightforward_count_init_if_better(table, index);
	// ps_strategy_sot_merge_rotate_up_count_init_if_better(table, index);
	// ps_strategy_sot_merge_rotate_down_count_init_if_better(table, index);
	// ps_strategy_sot_quick_count_init_if_better(table, index);
}
