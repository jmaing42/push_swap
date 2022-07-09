/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_tsb_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:05:00 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 13:24:17 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_tsb.h"

#include <stdint.h>

#include "ps_strategy_tsb_merge.h"
#include "ps_strategy_tsb_quick_rotate.h"
#include "ps_strategy_tsb_quick_no_rotate.h"

void	ps_strategy_tsb_init(
	t_ps_strategy_count *table,
	size_t index
)
{
	table[index].tsb.item.moves = table[index].tst.item.moves + index;
	table[index].tsb.func = ps_strategy_tsb_fallback_tst_execute;
	table[index].tsb.name = "tsb_fallback_tst";
	ps_strategy_tsb_merge_count_init_if_better(table, index);
	ps_strategy_tsb_quick_rotate_count_init_if_better(table, index);
	ps_strategy_tsb_quick_no_rotate_count_init_if_better(table, index);
}
