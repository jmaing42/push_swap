/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:07:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/07 16:58:06 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ps_solve_internal.h"
#include "ps_solve_tst.h"
#include "ps_solve_tsb.h"
#include "ps_solve_txt.h"
#include "ps_solve_txb.h"
#include "ps_solve_tot.h"
#include "ps_solve_tos.h"
#include "ps_solve_tob.h"
#include "ps_solve_sss.h"
#include "ps_solve_sxs.h"
#include "ps_solve_sot.h"
#include "ps_solve_sob.h"
#include "ps_solve_bst.h"
#include "ps_solve_bsb.h"
#include "ps_solve_bxt.h"
#include "ps_solve_bxb.h"
#include "ps_solve_bot.h"
#include "ps_solve_bos.h"
#include "ps_solve_bob.h"

#define COUNT 1000

static t_ps_solve_table	g_table[COUNT + 1];

int	main(void)
{
	g_table[0].bob.item.count = 0;
	g_table[1].bob.item.count = 3;
	g_table[2].bob.item.count = 6;
	g_table[3].bob.item.count = 9;
	g_table[4].bob.item.count = 12;
	g_table[5].bob.item.count = 15;
	g_table[6].bob.item.count = 18;
	g_table[7].bob.item.count = 22;
	g_table[8].bob.item.count = 25;
	g_table[0].bos.item.count = 0;
	g_table[1].bos.item.count = 2;
	g_table[2].bos.item.count = 4;
	g_table[3].bos.item.count = 7;
	g_table[4].bos.item.count = 9;
	g_table[5].bos.item.count = 12;
	g_table[6].bos.item.count = 14;
	g_table[7].bos.item.count = 17;
	g_table[8].bos.item.count = 20;
	g_table[0].bot.item.count = 0;
	g_table[1].bot.item.count = 2;
	g_table[2].bot.item.count = 4;
	g_table[3].bot.item.count = 7;
	g_table[4].bot.item.count = 9;
	g_table[5].bot.item.count = 13;
	g_table[6].bot.item.count = 16;
	g_table[7].bot.item.count = 19;
	g_table[8].bot.item.count = 23;
	g_table[0].bsb.item.count = 0;
	g_table[1].bsb.item.count = 0;
	g_table[2].bsb.item.count = 5;
	g_table[3].bsb.item.count = 9;
	g_table[4].bsb.item.count = 13;
	g_table[5].bsb.item.count = 17;
	g_table[6].bsb.item.count = 21;
	g_table[7].bsb.item.count = 25;
	g_table[8].bsb.item.count = 29;
	g_table[0].bst.item.count = 0;
	g_table[1].bst.item.count = 1;
	g_table[2].bst.item.count = 3;
	g_table[3].bst.item.count = 6;
	g_table[4].bst.item.count = 9;
	g_table[5].bst.item.count = 13;
	g_table[6].bst.item.count = 16;
	g_table[7].bst.item.count = 20;
	g_table[8].bst.item.count = 24;
	g_table[0].bxb.item.count = 0;
	g_table[1].bxb.item.count = 1;
	g_table[2].bxb.item.count = 5;
	g_table[3].bxb.item.count = 9;
	g_table[4].bxb.item.count = 13;
	g_table[5].bxb.item.count = 17;
	g_table[6].bxb.item.count = 21;
	g_table[7].bxb.item.count = 25;
	g_table[8].bxb.item.count = 29;
	g_table[0].bxt.item.count = 0;
	g_table[1].bxt.item.count = 1;
	g_table[2].bxt.item.count = 3;
	g_table[3].bxt.item.count = 6;
	g_table[4].bxt.item.count = 9;
	g_table[5].bxt.item.count = 13;
	g_table[6].bxt.item.count = 16;
	g_table[7].bxt.item.count = 19;
	g_table[8].bxt.item.count = 22;
	g_table[0].sob.item.count = 0;
	g_table[1].sob.item.count = 2;
	g_table[2].sob.item.count = 4;
	g_table[3].sob.item.count = 7;
	g_table[4].sob.item.count = 9;
	g_table[5].sob.item.count = 12;
	g_table[6].sob.item.count = 14;
	g_table[7].sob.item.count = 17;
	g_table[8].sob.item.count = 20;
	g_table[0].sot.item.count = 0;
	g_table[1].sot.item.count = 1;
	g_table[2].sot.item.count = 3;
	g_table[3].sot.item.count = 5;
	g_table[4].sot.item.count = 7;
	g_table[5].sot.item.count = 9;
	g_table[6].sot.item.count = 11;
	g_table[7].sot.item.count = 13;
	g_table[8].sot.item.count = 16;
	g_table[0].sss.item.count = 0;
	g_table[1].sss.item.count = 0;
	g_table[2].sss.item.count = 1;
	g_table[3].sss.item.count = 2;
	g_table[4].sss.item.count = 5;
	g_table[5].sss.item.count = 8;
	g_table[6].sss.item.count = 11;
	g_table[7].sss.item.count = 14;
	g_table[8].sss.item.count = 17;
	g_table[0].sxs.item.count = 0;
	g_table[1].sxs.item.count = 0;
	g_table[2].sxs.item.count = 1;
	g_table[3].sxs.item.count = 2;
	g_table[4].sxs.item.count = 5;
	g_table[5].sxs.item.count = 8;
	g_table[6].sxs.item.count = 10;
	g_table[7].sxs.item.count = 13;
	g_table[8].sxs.item.count = 16;
	g_table[0].tob.item.count = 0;
	g_table[1].tob.item.count = 2;
	g_table[2].tob.item.count = 4;
	g_table[3].tob.item.count = 7;
	g_table[4].tob.item.count = 9;
	g_table[5].tob.item.count = 13;
	g_table[6].tob.item.count = 16;
	g_table[7].tob.item.count = 19;
	g_table[8].tob.item.count = 23;
	g_table[0].tos.item.count = 0;
	g_table[1].tos.item.count = 1;
	g_table[2].tos.item.count = 3;
	g_table[3].tos.item.count = 5;
	g_table[4].tos.item.count = 7;
	g_table[5].tos.item.count = 9;
	g_table[6].tos.item.count = 11;
	g_table[7].tos.item.count = 13;
	g_table[8].tos.item.count = 16;
	g_table[0].tot.item.count = 0;
	g_table[1].tot.item.count = 1;
	g_table[2].tot.item.count = 3;
	g_table[3].tot.item.count = 6;
	g_table[4].tot.item.count = 8;
	g_table[5].tot.item.count = 10;
	g_table[6].tot.item.count = 13;
	g_table[7].tot.item.count = 16;
	g_table[8].tot.item.count = 19;
	g_table[0].tsb.item.count = 0;
	g_table[1].tsb.item.count = 1;
	g_table[2].tsb.item.count = 3;
	g_table[3].tsb.item.count = 6;
	g_table[4].tsb.item.count = 9;
	g_table[5].tsb.item.count = 13;
	g_table[6].tsb.item.count = 16;
	g_table[7].tsb.item.count = 20;
	g_table[8].tsb.item.count = 24;
	g_table[0].tst.item.count = 0;
	g_table[1].tst.item.count = 0;
	g_table[2].tst.item.count = 1;
	g_table[3].tst.item.count = 5;
	g_table[4].tst.item.count = 9;
	g_table[5].tst.item.count = 12;
	g_table[6].tst.item.count = 15;
	g_table[7].tst.item.count = 18;
	g_table[8].tst.item.count = 21;
	g_table[0].txb.item.count = 0;
	g_table[1].txb.item.count = 1;
	g_table[2].txb.item.count = 3;
	g_table[3].txb.item.count = 6;
	g_table[4].txb.item.count = 9;
	g_table[5].txb.item.count = 13;
	g_table[6].txb.item.count = 16;
	g_table[7].txb.item.count = 19;
	g_table[8].txb.item.count = 22;
	g_table[0].txt.item.count = 0;
	g_table[1].txt.item.count = 0;
	g_table[2].txt.item.count = 1;
	g_table[3].txt.item.count = 5;
	g_table[4].txt.item.count = 9;
	g_table[5].txt.item.count = 11;
	g_table[6].txt.item.count = 14;
	g_table[7].txt.item.count = 17;
	g_table[8].txt.item.count = 20;
	for (size_t i = 9; i <= COUNT; i++)
	{
		printf("%4zu: ", i);
		g_table[i].tst = ps_solve_tst_count_part(g_table, i);
		printf("%6zu", g_table[i].tst.item.count);
		g_table[i].txt = ps_solve_txt_count_part(g_table, i);
		printf("%6zu", g_table[i].txt.item.count);
		g_table[i].tsb = ps_solve_tsb_count_part(g_table, i);
		printf("%6zu", g_table[i].tsb.item.count);
		g_table[i].txb = ps_solve_txb_count_part(g_table, i);
		printf("%6zu", g_table[i].txb.item.count);
		g_table[i].tot = ps_solve_tot_count_part(g_table, i);
		printf("%6zu", g_table[i].tot.item.count);
		g_table[i].tos = ps_solve_tos_count_part(g_table, i);
		printf("%6zu", g_table[i].tos.item.count);
		g_table[i].tob = ps_solve_tob_count_part(g_table, i);
		printf("%6zu", g_table[i].tob.item.count);
		g_table[i].bst = ps_solve_bst_count_part(g_table, i);
		printf("%6zu", g_table[i].bst.item.count);
		g_table[i].bxt = ps_solve_bxt_count_part(g_table, i);
		printf("%6zu", g_table[i].bxt.item.count);
		g_table[i].bsb = ps_solve_bsb_count_part(g_table, i);
		printf("%6zu", g_table[i].bsb.item.count);
		g_table[i].bxb = ps_solve_bxb_count_part(g_table, i);
		printf("%6zu", g_table[i].bxb.item.count);
		g_table[i].bot = ps_solve_bot_count_part(g_table, i);
		printf("%6zu", g_table[i].bot.item.count);
		g_table[i].bos = ps_solve_bos_count_part(g_table, i);
		printf("%6zu", g_table[i].bos.item.count);
		g_table[i].bob = ps_solve_bob_count_part(g_table, i);
		printf("%6zu", g_table[i].bob.item.count);
		g_table[i].sss = ps_solve_sss_count_part(g_table, i);
		printf("%6zu", g_table[i].sss.item.count);
		g_table[i].sxs = ps_solve_sxs_count_part(g_table, i);
		printf("%6zu", g_table[i].sxs.item.count);
		g_table[i].sot = ps_solve_sot_count_part(g_table, i);
		printf("%6zu", g_table[i].sot.item.count);
		g_table[i].sob = ps_solve_sob_count_part(g_table, i);
		printf("%6zu", g_table[i].sob.item.count);
		printf("\n");
	}
	printf("solution: %zu\n", g_table[COUNT].sxs.item.count);
	return (0);
}
