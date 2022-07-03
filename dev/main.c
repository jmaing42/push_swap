/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:07:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/03 21:07:50 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../src/ps/strategy/ps_strategy.h"

int	main(void)
{
	t_ps_strategy_count	table[501];

	table[0].tst.moves = 0; table[1].tst.moves = 0; table[2].tst.moves = 1;
	table[0].tstx.moves = 0; table[1].tstx.moves = 0; table[2].tstx.moves = 1;
	table[0].tsb.moves = 0; table[1].tsb.moves = 1; table[2].tsb.moves = 3;
	table[0].tsbx.moves = 0; table[1].tsbx.moves = 1; table[2].tsbx.moves = 3;
	table[0].tot.moves = 0; table[1].tot.moves = 1; table[2].tot.moves = 3;
	table[0].tos.moves = 0; table[1].tos.moves = 1; table[2].tos.moves = 3;
	table[0].tob.moves = 0; table[1].tob.moves = 2; table[2].tob.moves = 5;
	table[0].bst.moves = 0; table[1].bst.moves = 1; table[2].bst.moves = 3;
	table[0].bstx.moves = 0; table[1].bstx.moves = 1; table[2].bstx.moves = 3;
	table[0].bsb.moves = 0; table[1].bsb.moves = 0; table[2].bsb.moves = 5;
	table[0].bsbx.moves = 0; table[1].bsbx.moves = 0; table[2].bsbx.moves = 5;
	table[0].bot.moves = 0; table[1].bot.moves = 2; table[2].bot.moves = 5;
	table[0].bos.moves = 0; table[1].bos.moves = 2; table[2].bos.moves = 5;
	table[0].bob.moves = 0; table[1].bob.moves = 3; table[2].bob.moves = 7;
	table[0].sss.moves = 0; table[1].sss.moves = 0; table[2].sss.moves = 1;
	table[0].sssx.moves = 0; table[1].sssx.moves = 0; table[2].sssx.moves = 1;
	table[0].sot.moves = 0; table[1].sot.moves = 1; table[2].sot.moves = 3;
	table[0].sos.moves = 0; table[1].sos.moves = 1; table[2].sos.moves = 3;
	table[0].sob.moves = 0; table[1].sob.moves = 2; table[2].sob.moves = 5;
	ps_strategy_bake(table, 3, 501);
	printf("solution: %zu\n", table[500].sss.moves);
	return (0);
}
