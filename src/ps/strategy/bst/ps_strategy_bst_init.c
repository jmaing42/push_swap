/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_bst_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:43:01 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 17:56:24 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_bst.h"

#include <stdint.h>

#include "ps_strategy_bst_merge_no_rotate.h"

// TODO: implement others

void	ps_strategy_bst_init(
	t_ps_strategy_count *table,
	size_t index
)
{
	table[index].bst.item.moves = table[index].tst.item.moves + index;
	table[index].bst.func = ps_strategy_bst_fallback_tst_execute;
	table[index].bst.name = "bst_fallback_tst";
	ps_strategy_bst_merge_no_rotate_count_init_if_better(table, index);
}
