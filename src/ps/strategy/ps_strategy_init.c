/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_bake.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:15:11 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/03 20:55:15 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_strategy.h"

#include "ps_strategy_tst.h"

void	ps_strategy_bake(
	t_ps_strategy_count *table,
	size_t count_from,
	size_t count_to_execlusive
)
{
	size_t	i;

	i = count_from - 1;
	while (++i < count_to_execlusive)
	{
		ps_strategy_tst_init(table, i);
		ps_strategy_tsb_init(table, i);
		ps_strategy_txt_init(table, i);
		ps_strategy_txb_init(table, i);
		ps_strategy_tot_init(table, i);
		ps_strategy_tos_init(table, i);
		ps_strategy_tob_init(table, i);
		ps_strategy_sss_init(table, i);
		ps_strategy_sxs_init(table, i);
		ps_strategy_sot_init(table, i);
		ps_strategy_sos_init(table, i);
		ps_strategy_sob_init(table, i);
		ps_strategy_bst_init(table, i);
		ps_strategy_bsb_init(table, i);
		ps_strategy_bxt_init(table, i);
		ps_strategy_bxb_init(table, i);
		ps_strategy_bot_init(table, i);
		ps_strategy_bos_init(table, i);
		ps_strategy_bob_init(table, i);
	}
}