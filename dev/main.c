/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:07:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/06 22:39:29 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../src/ps/strategy/ps_strategy.h"

#define COUNT 1000

int	main(void)
{
	t_ps_strategy_count	table[COUNT + 1];

	table[0].bob.moves = 0;
	table[1].bob.moves = 3;
	table[2].bob.moves = 6;
	table[3].bob.moves = 9;
	table[4].bob.moves = 12;
	table[5].bob.moves = 15;
	table[6].bob.moves = 18;
	table[7].bob.moves = 22;
	table[8].bob.moves = 25;
	table[0].bos.moves = 0;
	table[1].bos.moves = 2;
	table[2].bos.moves = 4;
	table[3].bos.moves = 7;
	table[4].bos.moves = 9;
	table[5].bos.moves = 12;
	table[6].bos.moves = 14;
	table[7].bos.moves = 17;
	table[8].bos.moves = 20;
	table[0].bot.moves = 0;
	table[1].bot.moves = 2;
	table[2].bot.moves = 4;
	table[3].bot.moves = 7;
	table[4].bot.moves = 9;
	table[5].bot.moves = 13;
	table[6].bot.moves = 16;
	table[7].bot.moves = 19;
	table[8].bot.moves = 23;
	table[0].bsb.moves = 0;
	table[1].bsb.moves = 0;
	table[2].bsb.moves = 5;
	table[3].bsb.moves = 9;
	table[4].bsb.moves = 13;
	table[5].bsb.moves = 17;
	table[6].bsb.moves = 21;
	table[7].bsb.moves = 25;
	table[8].bsb.moves = 29;
	table[0].bst.moves = 0;
	table[1].bst.moves = 1;
	table[2].bst.moves = 3;
	table[3].bst.moves = 6;
	table[4].bst.moves = 9;
	table[5].bst.moves = 13;
	table[6].bst.moves = 16;
	table[7].bst.moves = 20;
	table[8].bst.moves = 24;
	table[0].bxb.moves = 0;
	table[1].bxb.moves = 1;
	table[2].bxb.moves = 5;
	table[3].bxb.moves = 9;
	table[4].bxb.moves = 13;
	table[5].bxb.moves = 17;
	table[6].bxb.moves = 21;
	table[7].bxb.moves = 25;
	table[8].bxb.moves = 29;
	table[0].bxt.moves = 0;
	table[1].bxt.moves = 1;
	table[2].bxt.moves = 3;
	table[3].bxt.moves = 6;
	table[4].bxt.moves = 9;
	table[5].bxt.moves = 13;
	table[6].bxt.moves = 16;
	table[7].bxt.moves = 19;
	table[8].bxt.moves = 22;
	table[0].sob.moves = 0;
	table[1].sob.moves = 2;
	table[2].sob.moves = 4;
	table[3].sob.moves = 7;
	table[4].sob.moves = 9;
	table[5].sob.moves = 12;
	table[6].sob.moves = 14;
	table[7].sob.moves = 17;
	table[8].sob.moves = 20;
	table[0].sos.moves = 0;
	table[1].sos.moves = 1;
	table[2].sos.moves = 3;
	table[3].sos.moves = 5;
	table[4].sos.moves = 7;
	table[5].sos.moves = 9;
	table[6].sos.moves = 11;
	table[7].sos.moves = 13;
	table[8].sos.moves = 15;
	table[0].sot.moves = 0;
	table[1].sot.moves = 1;
	table[2].sot.moves = 3;
	table[3].sot.moves = 5;
	table[4].sot.moves = 7;
	table[5].sot.moves = 9;
	table[6].sot.moves = 11;
	table[7].sot.moves = 13;
	table[8].sot.moves = 16;
	table[0].sss.moves = 0;
	table[1].sss.moves = 0;
	table[2].sss.moves = 1;
	table[3].sss.moves = 2;
	table[4].sss.moves = 5;
	table[5].sss.moves = 8;
	table[6].sss.moves = 11;
	table[7].sss.moves = 14;
	table[8].sss.moves = 17;
	table[0].sxs.moves = 0;
	table[1].sxs.moves = 0;
	table[2].sxs.moves = 1;
	table[3].sxs.moves = 2;
	table[4].sxs.moves = 5;
	table[5].sxs.moves = 8;
	table[6].sxs.moves = 10;
	table[7].sxs.moves = 13;
	table[8].sxs.moves = 16;
	table[0].tob.moves = 0;
	table[1].tob.moves = 2;
	table[2].tob.moves = 4;
	table[3].tob.moves = 7;
	table[4].tob.moves = 9;
	table[5].tob.moves = 13;
	table[6].tob.moves = 16;
	table[7].tob.moves = 19;
	table[8].tob.moves = 23;
	table[0].tos.moves = 0;
	table[1].tos.moves = 1;
	table[2].tos.moves = 3;
	table[3].tos.moves = 5;
	table[4].tos.moves = 7;
	table[5].tos.moves = 9;
	table[6].tos.moves = 11;
	table[7].tos.moves = 13;
	table[8].tos.moves = 16;
	table[0].tot.moves = 0;
	table[1].tot.moves = 1;
	table[2].tot.moves = 3;
	table[3].tot.moves = 6;
	table[4].tot.moves = 8;
	table[5].tot.moves = 10;
	table[6].tot.moves = 13;
	table[7].tot.moves = 16;
	table[8].tot.moves = 19;
	table[0].tsb.moves = 0;
	table[1].tsb.moves = 1;
	table[2].tsb.moves = 3;
	table[3].tsb.moves = 6;
	table[4].tsb.moves = 9;
	table[5].tsb.moves = 13;
	table[6].tsb.moves = 16;
	table[7].tsb.moves = 20;
	table[8].tsb.moves = 24;
	table[0].tst.moves = 0;
	table[1].tst.moves = 0;
	table[2].tst.moves = 1;
	table[3].tst.moves = 5;
	table[4].tst.moves = 9;
	table[5].tst.moves = 12;
	table[6].tst.moves = 15;
	table[7].tst.moves = 18;
	table[8].tst.moves = 21;
	table[0].txb.moves = 0;
	table[1].txb.moves = 1;
	table[2].txb.moves = 3;
	table[3].txb.moves = 6;
	table[4].txb.moves = 9;
	table[5].txb.moves = 13;
	table[6].txb.moves = 16;
	table[7].txb.moves = 19;
	table[8].txb.moves = 22;
	table[0].txt.moves = 0;
	table[1].txt.moves = 0;
	table[2].txt.moves = 1;
	table[3].txt.moves = 5;
	table[4].txt.moves = 9;
	table[5].txt.moves = 11;
	table[6].txt.moves = 14;
	table[7].txt.moves = 17;
	table[8].txt.moves = 20;
	for (size_t i = 9; i <= COUNT; i++)
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
