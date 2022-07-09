/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_sss_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:41:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 14:42:26 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_sss.h"

#include <stdint.h>

#include "ps_strategy_sss_merge.h"
#include "ps_strategy_sss_quick.h"

void	ps_strategy_sss_init(
	t_ps_strategy_count *table,
	size_t index
)
{
	table[index].sss.item.moves = table[index].tst.item.moves;
	table[index].sss.func = ps_strategy_sss_fallback_tst_execute;
	table[index].sss.name = "sss_fallback_tst";
	ps_strategy_sss_merge_count_init_if_better(table, index);
	ps_strategy_sss_quick_count_init_if_better(table, index);
}
