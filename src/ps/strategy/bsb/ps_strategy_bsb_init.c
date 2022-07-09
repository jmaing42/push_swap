/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_bsb_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:10:40 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 18:20:50 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_bsb.h"

#include <stdint.h>

#include "ps_strategy_bsb_merge.h"

// TODO: implement others

void	ps_strategy_bst_init(
	t_ps_strategy_count *table,
	size_t index
)
{
	table[index].bst.item.moves = table[index].tsb.item.moves + index;
	table[index].bst.func = ps_strategy_bsb_fallback_tsb_execute;
	table[index].bst.name = "bst_fallback_tst";
	ps_strategy_bsb_merge_count_init_if_better(table, index);
}
