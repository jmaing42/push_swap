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

#include "ft_size_t.h"

typedef t_ps_strategy_count_item	(*t_f)(
	t_ps_strategy_count *table,
	size_t count,
	size_t (*calculate_with_exact_count)(
		const t_ps_strategy_count *table,
		size_t x,
		size_t y,
		size_t z
	)
);

typedef size_t						(*t_m)(size_t a, size_t b);

static void	ps_strategy_bake_part1(
	t_ps_strategy_count *table,
	size_t count
)
{
	const t_f	f = ps_strategy_count_get_optimal;

	table[count].tst_m1 = f(table, count, ps_strategy_count_tst_m1);
	table[count].tst_m2 = f(table, count, ps_strategy_count_tst_m2);
	table[count].tst_q1 = f(table, count, ps_strategy_count_tst_q1);
	table[count].tst_q2 = f(table, count, ps_strategy_count_tst_q2);
	table[count].tstx_m = f(table, count, ps_strategy_count_tstx_m);
	table[count].tstx_q = f(table, count, ps_strategy_count_tstx_q);
	table[count].tsb_m = f(table, count, ps_strategy_count_tsb_m);
	table[count].tsb_q = f(table, count, ps_strategy_count_tsb_q);
	table[count].tsbx_m = f(table, count, ps_strategy_count_tsbx_m);
	table[count].tsbx_q = f(table, count, ps_strategy_count_tsbx_q);
	table[count].tot_m1 = f(table, count, ps_strategy_count_tot_m1);
	table[count].tot_m2 = f(table, count, ps_strategy_count_tot_m2);
	table[count].tot_q1 = f(table, count, ps_strategy_count_tot_q1);
	table[count].tot_q2 = f(table, count, ps_strategy_count_tot_q2);
	table[count].tos_m = f(table, count, ps_strategy_count_tos_m);
	table[count].tos_q1 = f(table, count, ps_strategy_count_tos_q1);
	table[count].tos_q2 = f(table, count, ps_strategy_count_tos_q2);
	table[count].tob_m = f(table, count, ps_strategy_count_tob_m);
	table[count].tob_q = f(table, count, ps_strategy_count_tob_q);
	table[count].sss_m = f(table, count, ps_strategy_count_sss_m);
	table[count].sss_q = f(table, count, ps_strategy_count_sss_q);
	table[count].sssx_m = f(table, count, ps_strategy_count_sssx_m);
	table[count].sssx_q = f(table, count, ps_strategy_count_sssx_q);
}

static void	ps_strategy_bake_part2(
	t_ps_strategy_count *table,
	size_t count
)
{
	const t_f	f = ps_strategy_count_get_optimal;

	table[count].sot_m1 = f(table, count, ps_strategy_count_sot_m1);
	table[count].sot_m2 = f(table, count, ps_strategy_count_sot_m2);
	table[count].sot_q = f(table, count, ps_strategy_count_sot_q);
	table[count].sos_m1 = f(table, count, ps_strategy_count_sos_m1);
	table[count].sos_m2 = f(table, count, ps_strategy_count_sos_m2);
	table[count].sos_q1 = f(table, count, ps_strategy_count_sos_q1);
	table[count].sos_q2 = f(table, count, ps_strategy_count_sos_q2);
	table[count].sos_q3 = f(table, count, ps_strategy_count_sos_q3);
	table[count].sob_m1 = f(table, count, ps_strategy_count_sob_m1);
	table[count].sob_m2 = f(table, count, ps_strategy_count_sob_m2);
	table[count].sob_m3 = f(table, count, ps_strategy_count_sob_m3);
	table[count].sob_q = f(table, count, ps_strategy_count_sob_q);
	table[count].bst_m = f(table, count, ps_strategy_count_bst_m);
	table[count].bst_q = f(table, count, ps_strategy_count_bst_q);
	table[count].bstx_m1 = f(table, count, ps_strategy_count_bstx_m1);
	table[count].bstx_m2 = f(table, count, ps_strategy_count_bstx_m2);
	table[count].bstx_q = f(table, count, ps_strategy_count_bstx_q);
	table[count].bsb_m = f(table, count, ps_strategy_count_bsb_m);
	table[count].bsb_q = f(table, count, ps_strategy_count_bsb_q);
	table[count].bsbx_m = f(table, count, ps_strategy_count_bsbx_m);
	table[count].bsbx_q = f(table, count, ps_strategy_count_bsbx_q);
	table[count].bot_m1 = f(table, count, ps_strategy_count_bot_m1);
	table[count].bot_m2 = f(table, count, ps_strategy_count_bot_m2);
}

static void	ps_strategy_bake_part3(
	t_ps_strategy_count *table,
	size_t count
)
{
	const t_f					f = ps_strategy_count_get_optimal;
	const t_m					m = ft_size_t_min;
	t_ps_strategy_count *const	c = &table[count];

	c->bot_q = f(table, count, ps_strategy_count_bot_q);
	c->bos_m = f(table, count, ps_strategy_count_bos_m);
	c->bos_q1 = f(table, count, ps_strategy_count_bos_q1);
	c->bos_q2 = f(table, count, ps_strategy_count_bos_q2);
	c->bos_q3 = f(table, count, ps_strategy_count_bos_q3);
	c->bob_m = f(table, count, ps_strategy_count_bob_m);
	c->bob_q = f(table, count, ps_strategy_count_bob_q);
	c->tst.moves = m(m(m(c->tst_m1.moves, c->tst_m2.moves),
				c->tst_q1.moves), c->tst_q2.moves);
	c->tstx.moves = m(c->tstx_m.moves, c->tstx_q.moves);
	c->tsb.moves = m(c->tsb_m.moves, c->tsb_q.moves);
	c->tsbx.moves = m(c->tsbx_m.moves, c->tsbx_q.moves);
	c->tot.moves = m(m(m(c->tot_m1.moves, c->tot_m2.moves),
				c->tot_q1.moves), c->tot_q2.moves);
	c->tos.moves = m(m(c->tos_m.moves, c->tos_q1.moves), c->tos_q2.moves);
	c->tob.moves = m(c->tob_m.moves, c->tob_q.moves);
	c->sss.moves = m(c->sss_m.moves, c->sss_q.moves);
	c->sssx.moves = m(c->sssx_m.moves, c->sssx_q.moves);
	c->sot.moves = m(m(c->sot_m1.moves, c->sot_m2.moves), c->sot_q.moves);
	c->sos.moves = m(m(m(m(c->sos_m1.moves, c->sos_m2.moves),
					c->sos_q1.moves), c->sos_q2.moves), c->sos_q3.moves);
}

static void	ps_strategy_bake_part3(
	t_ps_strategy_count *table,
	size_t count
)
{
	const t_m					m = ft_size_t_min;
	t_ps_strategy_count *const	c = &table[count];

	c->sob.moves = m(m(m(c->sob_m1.moves, c->sob_m2.moves),
				c->sob_m3.moves), c->sob_q.moves);
	c->bst.moves = m(c->bst_m.moves, c->bst_q.moves);
	c->bstx.moves = m(m(c->bstx_m1.moves, c->bstx_m2.moves), c->bstx_q.moves);
	c->bsb.moves = m(c->bsb_m.moves, c->bsb_q.moves);
	c->bsbx.moves = m(c->bsbx_m.moves, c->bsbx_q.moves);
	c->bot.moves = m(m(c->bot_m1.moves, c->bot_m2.moves), c->bot_q.moves);
	c->bos.moves = m(m(m(c->bos_m.moves, c->bos_q1.moves),
				c->bos_q2.moves), c->bos_q3.moves);
	c->bob.moves = m(c->bob_m.moves, c->bob_q.moves);
}

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
		ps_strategy_bake_part1(table, i);
		ps_strategy_bake_part2(table, i);
		ps_strategy_bake_part3(table, i);
		ps_strategy_bake_part4(table, i);
	}
}
