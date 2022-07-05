/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:07:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/05 00:17:27 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../src/ps/strategy/ps_strategy.h"

#define COUNT 4242

int	main(void)
{
	t_ps_strategy_count	table[COUNT + 1];

	table[0].tst.moves = 0; table[1].tst.moves = 0; table[2].tst.moves = 1;
	table[0].txt.moves = 0; table[1].txt.moves = 0; table[2].txt.moves = 1;
	table[0].tsb.moves = 0; table[1].tsb.moves = 1; table[2].tsb.moves = 3;
	table[0].txb.moves = 0; table[1].txb.moves = 1; table[2].txb.moves = 3;
	table[0].tot.moves = 0; table[1].tot.moves = 1; table[2].tot.moves = 3;
	table[0].tos.moves = 0; table[1].tos.moves = 1; table[2].tos.moves = 3;
	table[0].tob.moves = 0; table[1].tob.moves = 2; table[2].tob.moves = 5;
	table[0].bst.moves = 0; table[1].bst.moves = 1; table[2].bst.moves = 3;
	table[0].bxt.moves = 0; table[1].bxt.moves = 1; table[2].bxt.moves = 3;
	table[0].bsb.moves = 0; table[1].bsb.moves = 0; table[2].bsb.moves = 5;
	table[0].bxb.moves = 0; table[1].bxb.moves = 0; table[2].bxb.moves = 5;
	table[0].bot.moves = 0; table[1].bot.moves = 2; table[2].bot.moves = 5;
	table[0].bos.moves = 0; table[1].bos.moves = 2; table[2].bos.moves = 5;
	table[0].bob.moves = 0; table[1].bob.moves = 3; table[2].bob.moves = 7;
	table[0].sss.moves = 0; table[1].sss.moves = 0; table[2].sss.moves = 1;
	table[0].sxs.moves = 0; table[1].sxs.moves = 0; table[2].sxs.moves = 1;
	table[0].sot.moves = 0; table[1].sot.moves = 1; table[2].sot.moves = 3;
	table[0].sos.moves = 0; table[1].sos.moves = 1; table[2].sos.moves = 3;
	table[0].sob.moves = 0; table[1].sob.moves = 2; table[2].sob.moves = 5;
	for (size_t i = 3; i <= COUNT; i++)
	{
		ps_strategy_bake(table, i, i + 1);
		printf("%4zu: ", i);
		printf("%6zu", table[i].tst.moves);
		printf("%6zu", table[i].txt.moves);
		printf("%6zu", table[i].tsb.moves);
		printf("%6zu", table[i].txb.moves);
		printf("%6zu", table[i].tot.moves);
		printf("%6zu", table[i].tos.moves);
		printf("%6zu", table[i].tob.moves);
		printf("%6zu", table[i].bst.moves);
		printf("%6zu", table[i].bxt.moves);
		printf("%6zu", table[i].bsb.moves);
		printf("%6zu", table[i].bxb.moves);
		printf("%6zu", table[i].bot.moves);
		printf("%6zu", table[i].bos.moves);
		printf("%6zu", table[i].bob.moves);
		printf("%6zu", table[i].sss.moves);
		printf("%6zu", table[i].sxs.moves);
		printf("%6zu", table[i].sot.moves);
		printf("%6zu", table[i].sos.moves);
		printf("%6zu", table[i].sob.moves);
		/*
		printf("     (");
		printf("%6zu", table[i].tst_m1.moves);
		printf("%6zu", table[i].tst_m2.moves);
		printf("%6zu", table[i].tst_q1.moves);
		printf("%6zu", table[i].tst_q2.moves);
		printf("%6zu", table[i].txt_m.moves);
		printf("%6zu", table[i].txt_q.moves);
		printf("%6zu", table[i].tsb_m.moves);
		printf("%6zu", table[i].tsb_q.moves);
		printf("%6zu", table[i].txb_m.moves);
		printf("%6zu", table[i].txb_q.moves);
		printf("%6zu", table[i].tot_m1.moves);
		printf("%6zu", table[i].tot_m2.moves);
		printf("%6zu", table[i].tot_q1.moves);
		printf("%6zu", table[i].tot_q2.moves);
		printf("%6zu", table[i].tos_m.moves);
		printf("%6zu", table[i].tos_q1.moves);
		printf("%6zu", table[i].tos_q2.moves);
		printf("%6zu", table[i].tob_m.moves);
		printf("%6zu", table[i].tob_q.moves);
		printf("%6zu", table[i].sss_m.moves);
		printf("%6zu", table[i].sss_q.moves);
		printf("%6zu", table[i].sxs_m.moves);
		printf("%6zu", table[i].sxs_q.moves);
		printf("%6zu", table[i].sot_m1.moves);
		printf("%6zu", table[i].sot_m2.moves);
		printf("%6zu", table[i].sot_q.moves);
		printf("%6zu", table[i].sos_m1.moves);
		printf("%6zu", table[i].sos_m2.moves);
		printf("%6zu", table[i].sos_q1.moves);
		printf("%6zu", table[i].sos_q2.moves);
		printf("%6zu", table[i].sob_m1.moves);
		printf("%6zu", table[i].sob_m2.moves);
		printf("%6zu", table[i].sob_m3.moves);
		printf("%6zu", table[i].sob_q.moves);
		printf("%6zu", table[i].bst_m1.moves);
		printf("%6zu", table[i].bst_m2.moves);
		printf("%6zu", table[i].bst_q.moves);
		printf("%6zu", table[i].bxt_m.moves);
		printf("%6zu", table[i].bxt_q.moves);
		printf("%6zu", table[i].bsb_m.moves);
		printf("%6zu", table[i].bsb_q.moves);
		printf("%6zu", table[i].bxb_m.moves);
		printf("%6zu", table[i].bxb_q.moves);
		printf("%6zu", table[i].bot_m1.moves);
		printf("%6zu", table[i].bot_m2.moves);
		printf("%6zu", table[i].bot_q.moves);
		printf("%6zu", table[i].bos_m.moves);
		printf("%6zu", table[i].bos_q1.moves);
		printf("%6zu", table[i].bos_q2.moves);
		printf("%6zu", table[i].bos_q3.moves);
		printf("%6zu", table[i].bob_m.moves);
		printf("%6zu", table[i].bob_q.moves);
		printf("     )");
		// */
		printf("\n");
	}
	printf("solution: %zu\n", table[COUNT].sxs.moves);
	return (0);
}
