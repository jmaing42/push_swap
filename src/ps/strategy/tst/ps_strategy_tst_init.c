/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_tst_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:05:00 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/08 20:59:24 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_tst.h"

#include <stdint.h>

#include "ps_strategy_tst_merge_early_rotate.h"
#include "ps_strategy_tst_merge_late_rotate.h"
#include "ps_strategy_tst_merge_no_rotate.h"

void	ps_strategy_tst_init(
	t_ps_strategy_count *table,
	size_t index
)
{
	table[index].tst.item.moves = SIZE_MAX;
	ps_strategy_tst_merge_early_rotate_count_init_if_better(table, index);
	ps_strategy_tst_merge_late_rotate_count_init_if_better(table, index);
	ps_strategy_tst_merge_no_rotate_count_init_if_better(table, index);
}
