/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:31:49 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/19 08:50:59 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SOLVE_H
# define PS_SOLVE_H

# include "ft_types.h"
# include "ps_stream.h"

typedef struct s_ps_solve_context
{
	t_ps_stream				*stream;
	struct s_ps_solve_table	*table;
	size_t					table_size;
}	t_ps_solve_context;

typedef struct s_ps_solve_count_size
{
	size_t	x;
	size_t	y;
	size_t	z;
}	t_ps_solve_count_size;

typedef t_err	(*t_ps_solve)(
					const t_ps_solve_context *context,
					const int *arr,
					t_ps_solve_count_size size,
					bool from_right);

typedef struct s_ps_solve_count_item
{
	t_ps_solve_count_size	size;
	size_t					count;
}	t_ps_solve_count_item;

typedef struct s_ps_solve_count_part
{
	t_ps_solve_count_item	item;
	t_ps_solve				solve;
}	t_ps_solve_count_part;

typedef struct s_ps_solve_table
{
	t_ps_solve_count_part	tst;
	t_ps_solve_count_part	tsb;
	t_ps_solve_count_part	txt;
	t_ps_solve_count_part	txb;
	t_ps_solve_count_part	tot;
	t_ps_solve_count_part	tos;
	t_ps_solve_count_part	tob;
	t_ps_solve_count_part	sss;
	t_ps_solve_count_part	sxs;
	t_ps_solve_count_part	sot;
	t_ps_solve_count_part	sob;
	t_ps_solve_count_part	bst;
	t_ps_solve_count_part	bsb;
	t_ps_solve_count_part	bxt;
	t_ps_solve_count_part	bxb;
	t_ps_solve_count_part	bot;
	t_ps_solve_count_part	bos;
	t_ps_solve_count_part	bob;
}	t_ps_solve_table;

t_err	ps_solve_tst(
			const t_ps_solve_context *context,
			const int *arr,
			size_t length,
			bool from_right);
t_err	ps_solve_tsb(
			const t_ps_solve_context *context,
			const int *arr,
			size_t length,
			bool from_right);
t_err	ps_solve_txt(
			const t_ps_solve_context *context,
			const int *arr,
			size_t length,
			bool from_right);
t_err	ps_solve_txb(
			const t_ps_solve_context *context,
			const int *arr,
			size_t length,
			bool from_right);
t_err	ps_solve_tot(
			const t_ps_solve_context *context,
			const int *arr,
			size_t length,
			bool from_right);
t_err	ps_solve_tos(
			const t_ps_solve_context *context,
			const int *arr,
			size_t length,
			bool from_right);
t_err	ps_solve_tob(
			const t_ps_solve_context *context,
			const int *arr,
			size_t length,
			bool from_right);
t_err	ps_solve_sss(
			const t_ps_solve_context *context,
			const int *arr,
			size_t length,
			bool from_right);
t_err	ps_solve_sxs(
			const t_ps_solve_context *context,
			const int *arr,
			size_t length,
			bool from_right);
t_err	ps_solve_sot(
			const t_ps_solve_context *context,
			const int *arr,
			size_t length,
			bool from_right);
t_err	ps_solve_sob(
			const t_ps_solve_context *context,
			const int *arr,
			size_t length,
			bool from_right);
t_err	ps_solve_bst(
			const t_ps_solve_context *context,
			const int *arr,
			size_t length,
			bool from_right);
t_err	ps_solve_bsb(
			const t_ps_solve_context *context,
			const int *arr,
			size_t length,
			bool from_right);
t_err	ps_solve_bxt(
			const t_ps_solve_context *context,
			const int *arr,
			size_t length,
			bool from_right);
t_err	ps_solve_bxb(
			const t_ps_solve_context *context,
			const int *arr,
			size_t length,
			bool from_right);
t_err	ps_solve_bot(
			const t_ps_solve_context *context,
			const int *arr,
			size_t length,
			bool from_right);
t_err	ps_solve_bos(
			const t_ps_solve_context *context,
			const int *arr,
			size_t length,
			bool from_right);
t_err	ps_solve_bob(
			const t_ps_solve_context *context,
			const int *arr,
			size_t length,
			bool from_right);

#endif
