/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_txt_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:33:36 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 00:35:21 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_txt.h"

#include <stdint.h>

#include "ps_strategy_txt_merge_intuitive.h"
#include "ps_strategy_txt_merge_unintuitive.h"
#include "ps_strategy_txt_quick_intuitive.h"
#include "ps_strategy_txt_quick_unintuitive.h"

void	ps_strategy_txt_init(
	t_ps_strategy_count *table,
	size_t index
)
{
	table[index].txt.item.moves = table[index].tst.item.moves;
	table[index].txt.func = ps_strategy_txt_fallback_tst_execute;
	table[index].txt.name = "txt_fallback_tst";
	ps_strategy_txt_merge_intuitive_count_init_if_better(table, index);
	ps_strategy_txt_merge_unintuitive_count_init_if_better(table, index);
	ps_strategy_txt_quick_intuitive_count_init_if_better(table, index);
	ps_strategy_txt_quick_unintuitive_count_init_if_better(table, index);
}
