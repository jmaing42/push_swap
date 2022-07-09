/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_txb_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 09:25:01 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 09:43:55 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_txb.h"

#include <stdint.h>

#include "ps_strategy_txb_merge_intuitive.h"
#include "ps_strategy_txb_merge_unintuitive.h"
#include "ps_strategy_txb_quick_intuitive.h"
#include "ps_strategy_txb_quick_unintuitive.h"

void	ps_strategy_txt_init(
	t_ps_strategy_count *table,
	size_t index
)
{
	table[index].txb.item.moves = table[index].txt.item.moves + index;
	table[index].txb.func = ps_strategy_txb_fallback_txt_execute;
	table[index].txb.name = "txb_fallback_txt";
	ps_strategy_txb_merge_intuitive_count_init_if_better(table, index);
	ps_strategy_txb_merge_unintuitive_count_init_if_better(table, index);
	ps_strategy_txb_quick_intuitive_count_init_if_better(table, index);
	ps_strategy_txb_quick_unintuitive_count_init_if_better(table, index);
}
