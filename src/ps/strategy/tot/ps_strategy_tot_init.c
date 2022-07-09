/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_tot_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 09:49:37 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 09:49:37 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy_tot.h"

#include <stdint.h>

#include "ps_strategy_tot_merge_rotate.h"
#include "ps_strategy_tot_merge_no_rotate.h"
#include "ps_strategy_tot_quick_rotate.h"
#include "ps_strategy_tot_quick_no_rotate.h"

void	ps_strategy_tot_init(
	t_ps_strategy_count *table,
	size_t index
)
{
	table[index].tst.item.moves = SIZE_MAX;
	ps_strategy_tot_merge_rotate_count_init_if_better(table, index);
	ps_strategy_tot_merge_no_rotate_count_init_if_better(table, index);
	ps_strategy_tot_quick_rotate_count_init_if_better(table, index);
	ps_strategy_tot_quick_no_rotate_count_init_if_better(table, index);
}
