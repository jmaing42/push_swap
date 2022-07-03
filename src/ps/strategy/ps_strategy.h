/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:45:05 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/03 20:13:55 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRATEGY_H
# define PS_STRATEGY_H

# include <stddef.h>

typedef struct s_ps_strategy_count_item
{
	size_t	x;
	size_t	y;
	size_t	z;
	size_t	moves;
}	t_ps_strategy_count_item;

typedef struct s_ps_strategy_count_part
{
	size_t	moves;
	// TODO: add function pointer
}	t_ps_strategy_count_part;

typedef struct s_ps_strategy_count
{
	t_ps_strategy_count_item	tst_m1;
	t_ps_strategy_count_item	tst_m2;
	t_ps_strategy_count_item	tst_q1;
	t_ps_strategy_count_item	tst_q2;
	t_ps_strategy_count_item	tstx_m;
	t_ps_strategy_count_item	tstx_q;
	t_ps_strategy_count_item	tsb_m;
	t_ps_strategy_count_item	tsb_q;
	t_ps_strategy_count_item	tsbx_m;
	t_ps_strategy_count_item	tsbx_q;
	t_ps_strategy_count_item	tot_m1;
	t_ps_strategy_count_item	tot_m2;
	t_ps_strategy_count_item	tot_q1;
	t_ps_strategy_count_item	tot_q2;
	t_ps_strategy_count_item	tos_m;
	t_ps_strategy_count_item	tos_q1;
	t_ps_strategy_count_item	tos_q2;
	t_ps_strategy_count_item	tob_m;
	t_ps_strategy_count_item	tob_q;
	t_ps_strategy_count_item	sss_m;
	t_ps_strategy_count_item	sss_q;
	t_ps_strategy_count_item	sssx_m;
	t_ps_strategy_count_item	sssx_q;
	t_ps_strategy_count_item	sot_m1;
	t_ps_strategy_count_item	sot_m2;
	t_ps_strategy_count_item	sot_q;
	t_ps_strategy_count_item	sos_m1;
	t_ps_strategy_count_item	sos_m2;
	t_ps_strategy_count_item	sos_q1;
	t_ps_strategy_count_item	sos_q2;
	t_ps_strategy_count_item	sos_q3;
	t_ps_strategy_count_item	sob_m1;
	t_ps_strategy_count_item	sob_m2;
	t_ps_strategy_count_item	sob_m3;
	t_ps_strategy_count_item	sob_q;
	t_ps_strategy_count_item	bst_m;
	t_ps_strategy_count_item	bst_q;
	t_ps_strategy_count_item	bstx_m1;
	t_ps_strategy_count_item	bstx_m2;
	t_ps_strategy_count_item	bstx_q;
	t_ps_strategy_count_item	bsb_m;
	t_ps_strategy_count_item	bsb_q;
	t_ps_strategy_count_item	bsbx_m;
	t_ps_strategy_count_item	bsbx_q;
	t_ps_strategy_count_item	bot_m1;
	t_ps_strategy_count_item	bot_m2;
	t_ps_strategy_count_item	bot_q;
	t_ps_strategy_count_item	bos_m;
	t_ps_strategy_count_item	bos_q1;
	t_ps_strategy_count_item	bos_q2;
	t_ps_strategy_count_item	bos_q3;
	t_ps_strategy_count_item	bob_m;
	t_ps_strategy_count_item	bob_q;
	t_ps_strategy_count_part	tst;
	t_ps_strategy_count_part	tstx;
	t_ps_strategy_count_part	tsb;
	t_ps_strategy_count_part	tsbx;
	t_ps_strategy_count_part	tot;
	t_ps_strategy_count_part	tos;
	t_ps_strategy_count_part	tob;
	t_ps_strategy_count_part	bst;
	t_ps_strategy_count_part	bstx;
	t_ps_strategy_count_part	bsb;
	t_ps_strategy_count_part	bsbx;
	t_ps_strategy_count_part	bot;
	t_ps_strategy_count_part	bos;
	t_ps_strategy_count_part	bob;
	t_ps_strategy_count_part	sss;
	t_ps_strategy_count_part	sssx;
	t_ps_strategy_count_part	sot;
	t_ps_strategy_count_part	sob;
	t_ps_strategy_count_part	sos;
}	t_ps_strategy_count;

size_t						ps_strategy_count_tst_m1(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_tst_m2(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_tst_q2(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_tst_q2(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_tstx_m(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_tstx_q(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_tsb_m(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_tsb_q(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_tsbx_m(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_tsbx_q(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_tot_m1(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_tot_m2(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_tot_q2(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_tot_q2(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_tos_m(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_tos_q2(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_tos_q2(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_tob_m(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_tob_q(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_sss_m(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_sss_q(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_sssx_m(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_sssx_q(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_sot_m1(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_sot_m2(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_sot_q(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_sos_m1(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_sos_m2(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_sos_q1(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_sos_q2(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_sos_q3(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_sob_m1(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_sob_m2(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_sob_m3(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_sob_q(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_bst_m(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_bst_q(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_bstx_m1(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_bstx_m2(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_bstx_q(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_bsb_m(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_bsb_q(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_bsbx_m(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_bsbx_q(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_bot_m1(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_bot_m2(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_bot_q(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_bos_m(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_bos_q1(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_bos_q2(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_bos_q3(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_bob_m(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_bob_q(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);

t_ps_strategy_count_item	ps_strategy_count_get_optimal(
								t_ps_strategy_count *map,
								size_t count,
								size_t (*calculate_with_exact_count)(
									const t_ps_strategy_count *map,
									size_t x,
									size_t y,
									size_t z));

#endif
