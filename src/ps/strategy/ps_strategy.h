/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:45:05 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/02 14:02:46 by Juyeong Maing    ###   ########.fr       */
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

size_t	ps_strategy_count_tst_m1(
			const t_ps_strategy_count *table,
			size_t x,
			size_t y,
			size_t z);
size_t	ps_strategy_count_tst_m2(
			const t_ps_strategy_count *table,
			size_t x,
			size_t y,
			size_t z);
size_t	ps_strategy_count_tst_q2(
			const t_ps_strategy_count *table,
			size_t x,
			size_t y,
			size_t z);
size_t	ps_strategy_count_tst_q2(
			const t_ps_strategy_count *table,
			size_t x,
			size_t y,
			size_t z);

#endif
