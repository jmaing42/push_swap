/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:31:49 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/18 09:19:00 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SOLVE_INTERNAL_H
# define PS_SOLVE_INTERNAL_H

# include "ps_solve.h"

# include "ft_types.h"

typedef size_t	(*t_ps_solve_count)(
					t_ps_solve_context *context,
					size_t x,
					size_t y,
					size_t z);

typedef struct s_ps_solve_count_tuple
{
	t_ps_solve			solver;
	t_ps_solve_count	counter;
}	t_ps_solve_count_tuple;

typedef struct s_ps_solve_util_array
{
	int		*array;
	size_t	length;
}	t_ps_solve_util_array;

typedef struct s_ps_solve_util_parts
{
	t_ps_solve_util_array	a;
	t_ps_solve_util_array	b;
	t_ps_solve_util_array	c;
	int						memory[];
}	t_ps_solve_util_parts;

typedef struct s_ps_solve_util_divide
{
	t_ps_stream					*stream;
	const t_ps_solve_util_array	*p;
	const t_ps_solve_util_array	*q;
	const t_ps_solve_util_array	*r;
	bool						from_right;
}	t_ps_solve_util_divide;

typedef struct s_ps_solve_strategy
{
	t_ps_solve_count_size	size;
	t_ps_solve				solve;
}	t_ps_solve_strategy;

t_ps_solve_count_part	ps_solve_count_part(
							const t_ps_solve_count_tuple *strategies,
							size_t length,
							size_t count);
t_ps_solve_count_item	ps_solve_util_try_all_permutation(
							t_ps_solve_count strategy,
							size_t count);

void					ps_solve_util_inverse(
							const t_ps_solve_util_array	*array);
void					ps_solve_util_reverse(
							const t_ps_solve_util_array	*array);

t_err					ps_solve_util_move_tsb(
							t_ps_stream *stream,
							bool from_right);
t_err					ps_solve_util_move_tot(
							t_ps_stream *stream,
							bool from_right);
t_err					ps_solve_util_move_tob(
							t_ps_stream *stream,
							bool from_right);
t_err					ps_solve_util_move_bst(
							t_ps_stream *stream,
							bool from_right);
t_err					ps_solve_util_move_bot(
							t_ps_stream *stream,
							bool from_right);
t_err					ps_solve_util_move_bob(
							t_ps_stream *stream,
							bool from_right);

t_err					ps_solve_util_collect_to_top(
							t_ps_solve_util_divide params);
t_err					ps_solve_util_collect_to_bottom(
							t_ps_solve_util_divide params);
t_err					ps_solve_util_divide_from_top(
							t_ps_solve_util_parts params);
t_err					ps_solve_util_divide_from_bottom(
							t_ps_solve_util_parts params);
t_err					ps_solve_util_rotate_up(
							t_ps_stream *stream,
							t_ps_solve_util_array *left,
							t_ps_solve_util_array *right,
							bool from_right);
t_err					ps_solve_util_rotate_down(
							t_ps_stream *stream,
							t_ps_solve_util_array *left,
							t_ps_solve_util_array *right,
							bool from_right);

t_ps_solve_util_parts	*ps_solve_util_allocate_collect(
							int *array,
							size_t top,
							size_t middle,
							size_t bottom);
t_ps_solve_util_parts	ps_solve_util_allocate_divide_from_top_stb(
							t_ps_solve_util_divide params);
t_ps_solve_util_parts	ps_solve_util_allocate_divide_from_bottom_stb(
							t_ps_solve_util_divide params);
t_ps_solve_util_parts	ps_solve_util_allocate_divide_from_top_sbt(
							t_ps_solve_util_divide params);
t_ps_solve_util_parts	ps_solve_util_allocate_divide_from_bottom_sbt(
							t_ps_solve_util_divide params);
t_ps_solve_util_parts	ps_solve_util_allocate_divide_from_top_tsb(
							t_ps_solve_util_divide params);
t_ps_solve_util_parts	ps_solve_util_allocate_divide_from_bottom_tsb(
							t_ps_solve_util_divide params);
t_ps_solve_util_parts	ps_solve_util_allocate_divide_from_top_tbs(
							t_ps_solve_util_divide params);
t_ps_solve_util_parts	ps_solve_util_allocate_divide_from_bottom_tbs(
							t_ps_solve_util_divide params);
t_ps_solve_util_parts	ps_solve_util_allocate_divide_from_top_bst(
							t_ps_solve_util_divide params);
t_ps_solve_util_parts	ps_solve_util_allocate_divide_from_bottom_bst(
							t_ps_solve_util_divide params);
t_ps_solve_util_parts	ps_solve_util_allocate_divide_from_top_bts(
							t_ps_solve_util_divide params);
t_ps_solve_util_parts	ps_solve_util_allocate_divide_from_bottom_bts(
							t_ps_solve_util_divide params);

t_err					ps_solve_tsb_merge_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tsb_merge_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_tsb_quick_no_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tsb_quick_no_rotate_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_tsb_quick_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tsb_quick_rotate_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_txt_merge_no_twist_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_txt_merge_no_twist_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_txt_merge_twist_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_txt_merge_twist_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_txt_quick_no_twist_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_txt_quick_no_twist_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_txt_quick_twist_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_txt_quick_twist_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_txb_merge_no_twist_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_txb_merge_no_twist_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_txb_merge_twist_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_txb_merge_twist_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_txb_quick_no_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_txb_quick_no_rotate_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_txb_quick_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_txb_quick_rotate_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_tot_merge_no_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tot_merge_no_rotate_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_tot_merge_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tot_merge_rotate_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_tot_quick_no_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tot_quick_no_rotate_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_tot_quick_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tot_quick_rotate_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_tos_merge_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tos_merge_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_tos_quick_twist_up_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tos_quick_twist_up_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_tos_quick_twist_down_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tos_quick_twist_down_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_tos_quick_rotate_up_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tos_quick_rotate_up_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_tos_quick_rotate_down_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tos_quick_rotate_down_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_tos_quick_no_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tos_quick_no_rotate_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_tob_merge_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tob_merge_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_tob_quick_no_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tob_quick_no_rotate_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_tob_quick_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tob_quick_rotate_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_sss_merge_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_sss_merge_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_sss_quick_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_sss_quick_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_sxs_merge_no_twist_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_sxs_merge_no_twist_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_sxs_merge_twist_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_sxs_merge_twist_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_sxs_quick_no_twist_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_sxs_quick_no_twist_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_sxs_quick_twist_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_sxs_quick_twist_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_sot_merge_twist_up_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_sot_merge_twist_up_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_sot_merge_twist_down_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_sot_merge_twist_down_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_sot_merge_rotate_up_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_sot_merge_rotate_up_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_sot_merge_rotate_down_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_sot_merge_rotate_down_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_sot_merge_no_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_sot_merge_no_rotate_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_sot_quick_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_sot_quick_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_sob_merge_twist_up_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_sob_merge_twist_up_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_sob_merge_twist_down_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_sob_merge_twist_down_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_sob_merge_rotate_up_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_sob_merge_rotate_up_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_sob_merge_rotate_down_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_sob_merge_rotate_down_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_sob_merge_no_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_sob_merge_no_rotate_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_sob_quick_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_sob_quick_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bst_merge_no_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_bst_merge_no_rotate_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bst_merge_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_bst_merge_rotate_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bst_quick_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_bst_quick_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bsb_merge_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_bsb_merge_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bsb_quick_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_bsb_quick_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bxt_merge_no_twist_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_bxt_merge_no_twist_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bxt_merge_twist_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_bxt_merge_twist_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bxt_quick_no_twist_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_bxt_quick_no_twist_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bxt_quick_twist_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_bxt_quick_twist_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bxb_merge_no_twist_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_bxb_merge_no_twist_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bxb_merge_twist_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_bxb_merge_twist_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bxb_quick_no_twist_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_bxb_quick_no_twist_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bxb_quick_twist_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_bxb_quick_twist_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bot_merge_no_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_bot_merge_no_rotate_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bot_merge_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_bot_merge_rotate_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bot_quick_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_bot_quick_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bos_merge_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_bos_merge_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bos_quick_twist_up_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_bos_quick_twist_up_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bos_quick_twist_down_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_bos_quick_twist_down_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bos_quick_rotate_up_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_bos_quick_rotate_up_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bos_quick_rotate_down_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_bos_quick_rotate_down_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bos_quick_no_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_bos_quick_no_rotate_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bob_merge_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_bob_merge_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bob_quick_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_bob_quick_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

#endif
