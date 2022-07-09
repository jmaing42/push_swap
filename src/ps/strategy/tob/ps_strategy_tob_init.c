/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_tob_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:05:00 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 12:44:46 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_tob.h"

#include <stdint.h>

#include "ps_strategy_tob_merge.h"
#include "ps_strategy_tob_quick.h"

void	ps_strategy_tob_init(
	t_ps_strategy_count *table,
	size_t index
)
{
	table[index].tob.item.moves = table[index].tot.item.moves + index;
	table[index].tob.func = ps_strategy_tob_fallback_tst_execute;
	table[index].tob.name = "tob_fallback_tot";
	ps_strategy_tob_merge_count_init_if_better(table, index);
	ps_strategy_tob_quick_count_init_if_better(table, index);
}
