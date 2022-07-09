/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_tos_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 10:40:25 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 12:41:16 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_tos.h"

#include <stdint.h>

#include "ps_strategy_tos_merge.h"
#include "ps_strategy_tos_quick_twist_up.h"
#include "ps_strategy_tos_quick_twist_down.h"
#include "ps_strategy_tos_quick_straightforward.h"
#include "ps_strategy_tos_quick_rotate_up.h"
#include "ps_strategy_tos_quick_rotate_down.h"

void	ps_strategy_tos_init(
	t_ps_strategy_count *table,
	size_t index
)
{
	table[index].tos.item.moves = table[index].tot.item.moves;
	table[index].tos.func = ps_strategy_tos_fallback_tot_execute;
	table[index].tos.name = "tos_fallback_tot";
	ps_strategy_tos_merge_count_init_if_better(table, index);
	ps_strategy_tos_quick_twist_up_count_init_if_better(table, index);
	ps_strategy_tos_quick_twist_down_count_init_if_better(table, index);
	ps_strategy_tos_quick_straightforward_count_init_if_better(table, index);
	ps_strategy_tos_quick_rotate_up_count_init_if_better(table, index);
	ps_strategy_tos_quick_rotate_down_count_init_if_better(table, index);
}
