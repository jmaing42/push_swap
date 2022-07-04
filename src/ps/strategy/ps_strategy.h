/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:45:05 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/05 00:15:17 by Juyeong Maing    ###   ########.fr       */
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
	t_ps_strategy_count_item	txt_m;
	t_ps_strategy_count_item	txt_q;
	t_ps_strategy_count_item	tsb_m;
	t_ps_strategy_count_item	tsb_q;
	t_ps_strategy_count_item	txb_m;
	t_ps_strategy_count_item	txb_q;
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
	t_ps_strategy_count_item	sxs_m;
	t_ps_strategy_count_item	sxs_q;
	t_ps_strategy_count_item	sot_m1;
	t_ps_strategy_count_item	sot_m2;
	t_ps_strategy_count_item	sot_q;
	t_ps_strategy_count_item	sos_m1;
	t_ps_strategy_count_item	sos_m2;
	t_ps_strategy_count_item	sos_q1;
	t_ps_strategy_count_item	sos_q2;
	t_ps_strategy_count_item	sob_m1;
	t_ps_strategy_count_item	sob_m2;
	t_ps_strategy_count_item	sob_m3;
	t_ps_strategy_count_item	sob_q;
	t_ps_strategy_count_item	bst_m1;
	t_ps_strategy_count_item	bst_m2;
	t_ps_strategy_count_item	bst_q;
	t_ps_strategy_count_item	bxt_m;
	t_ps_strategy_count_item	bxt_q;
	t_ps_strategy_count_item	bsb_m;
	t_ps_strategy_count_item	bsb_q;
	t_ps_strategy_count_item	bxb_m;
	t_ps_strategy_count_item	bxb_q;
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
	t_ps_strategy_count_part	txt;
	t_ps_strategy_count_part	tsb;
	t_ps_strategy_count_part	txb;
	t_ps_strategy_count_part	tot;
	t_ps_strategy_count_part	tos;
	t_ps_strategy_count_part	tob;
	t_ps_strategy_count_part	bst;
	t_ps_strategy_count_part	bxt;
	t_ps_strategy_count_part	bsb;
	t_ps_strategy_count_part	bxb;
	t_ps_strategy_count_part	bot;
	t_ps_strategy_count_part	bos;
	t_ps_strategy_count_part	bob;
	t_ps_strategy_count_part	sss;
	t_ps_strategy_count_part	sxs;
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
size_t						ps_strategy_count_tst_q1(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_tst_q2(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_txt_m(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_txt_q(
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
size_t						ps_strategy_count_txb_m(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_txb_q(
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
size_t						ps_strategy_count_tot_q1(
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
size_t						ps_strategy_count_tos_q1(
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
size_t						ps_strategy_count_sxs_m(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_sxs_q(
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
size_t						ps_strategy_count_bst_m1(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_bst_m2(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_bst_q(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_bxt_m(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_bxt_q(
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
size_t						ps_strategy_count_bxb_m(
								const t_ps_strategy_count *table,
								size_t x,
								size_t y,
								size_t z);
size_t						ps_strategy_count_bxb_q(
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
								t_ps_strategy_count *table,
								size_t count,
								size_t (*calculate_with_exact_count)(
									const t_ps_strategy_count *table,
									size_t x,
									size_t y,
									size_t z));

void						ps_strategy_bake(
								t_ps_strategy_count *table,
								size_t count_from,
								size_t count_to_exclusive);

#endif
