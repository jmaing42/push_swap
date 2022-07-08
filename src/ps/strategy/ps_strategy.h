/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:45:05 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/08 09:28:52 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRATEGY_H
# define PS_STRATEGY_H

# include <stddef.h>

# include "ps_stream.h"

typedef struct s_ps_strategy_count_item
{
	size_t	x;
	size_t	y;
	size_t	z;
	size_t	moves;
}	t_ps_strategy_count_item;

typedef t_err	(*t_ps_solve)(struct s_ps_solve_param context);

typedef struct s_ps_strategy_count_part
{
	t_ps_strategy_count_item	item;
	t_ps_solve					func;
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

typedef struct s_ps_solve_param
{
	t_ps_strategy_count	*map;
	t_ps_stream			*output;
	size_t				count;
	int					*arr;
	bool				from_right;
}	t_ps_solve_param;

void						ps_strategy_tst_init(
								t_ps_strategy_count *table,
								t_ps_strategy_count_part *out_result);
void						ps_strategy_tsb_init(
								t_ps_strategy_count *table,
								t_ps_strategy_count_part *out_result);
void						ps_strategy_txt_init(
								t_ps_strategy_count *table,
								t_ps_strategy_count_part *out_result);
void						ps_strategy_txb_init(
								t_ps_strategy_count *table,
								t_ps_strategy_count_part *out_result);
void						ps_strategy_tot_init(
								t_ps_strategy_count *table,
								t_ps_strategy_count_part *out_result);
void						ps_strategy_tos_init(
								t_ps_strategy_count *table,
								t_ps_strategy_count_part *out_result);
void						ps_strategy_tob_init(
								t_ps_strategy_count *table,
								t_ps_strategy_count_part *out_result);
void						ps_strategy_sss_init(
								t_ps_strategy_count *table,
								t_ps_strategy_count_part *out_result);
void						ps_strategy_sxs_init(
								t_ps_strategy_count *table,
								t_ps_strategy_count_part *out_result);
void						ps_strategy_sot_init(
								t_ps_strategy_count *table,
								t_ps_strategy_count_part *out_result);
void						ps_strategy_sos_init(
								t_ps_strategy_count *table,
								t_ps_strategy_count_part *out_result);
void						ps_strategy_sob_init(
								t_ps_strategy_count *table,
								t_ps_strategy_count_part *out_result);
void						ps_strategy_bst_init(
								t_ps_strategy_count *table,
								t_ps_strategy_count_part *out_result);
void						ps_strategy_bsb_init(
								t_ps_strategy_count *table,
								t_ps_strategy_count_part *out_result);
void						ps_strategy_bxt_init(
								t_ps_strategy_count *table,
								t_ps_strategy_count_part *out_result);
void						ps_strategy_bxb_init(
								t_ps_strategy_count *table,
								t_ps_strategy_count_part *out_result);
void						ps_strategy_bot_init(
								t_ps_strategy_count *table,
								t_ps_strategy_count_part *out_result);
void						ps_strategy_bos_init(
								t_ps_strategy_count *table,
								t_ps_strategy_count_part *out_result);
void						ps_strategy_bob_init(
								t_ps_strategy_count *table,
								t_ps_strategy_count_part *out_result);

#endif
