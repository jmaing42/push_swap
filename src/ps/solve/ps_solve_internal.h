/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:31:49 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/18 00:48:09 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SOLVE_INTERNAL_H
# define PS_SOLVE_INTERNAL_H

# include "ps_solve.h"

typedef size_t	(*t_ps_solve_count)(
					t_ps_solve_context *context,
					int *arr,
					size_t length);

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
	int						*memory;
	t_ps_solve_util_array	first;
	t_ps_solve_util_array	second;
	t_ps_solve_util_array	third;
}	t_ps_solve_util_parts;

t_ps_solve_count_part	ps_solve_count_part(
							t_ps_solve_count_tuple *strategies,
							size_t count);
t_ps_solve_count_item	ps_solve_util_try_all_permutation(
							t_ps_solve_count strategy,
							size_t count);

void					ps_solve_util_inverse(
							int *arr,
							size_t count);
void					ps_solve_util_reverse(
							int *arr,
							size_t count);

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

t_ps_solve_util_parts	ps_solve_util_allocate(
							size_t first,
							size_t second,
							size_t third);
t_ps_solve_util_parts	ps_solve_util_allocate_quick(
							int *array,
							size_t first,
							size_t second,
							size_t third);
t_ps_solve_util_parts	ps_solve_util_allocate_merge(
							int *array,
							size_t first,
							size_t second,
							size_t third);

t_err					ps_solve_tst_merge_no_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tst_merge_no_rotate_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_tst_merge_early_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tst_merge_early_rotate_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_tst_merge_late_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tst_merge_late_rotate_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_tst_quick_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tst_quick_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_tsb_merge_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tsb_merge_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_tsb_quick_no_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tsb_quick_no_rotate_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_tsb_quick_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tsb_quick_rotate_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_txt_merge_no_twist_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_txt_merge_no_twist_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_txt_merge_twist_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_txt_merge_twist_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_txt_quick_no_twist_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_txt_quick_no_twist_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_txt_quick_twist_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_txt_quick_twist_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_txb_merge_no_twist_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_txb_merge_no_twist_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_txb_merge_twist_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_txb_merge_twist_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_txb_quick_no_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_txb_quick_no_rotate_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_txb_quick_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_txb_quick_rotate_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_tot_merge_no_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tot_merge_no_rotate_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_tot_merge_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tot_merge_rotate_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_tot_quick_no_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tot_quick_no_rotate_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_tot_quick_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tot_quick_rotate_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_tos_merge_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tos_merge_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_tos_quick_twist_up_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tos_quick_twist_up_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_tos_quick_twist_down_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tos_quick_twist_down_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_tos_quick_rotate_up_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tos_quick_rotate_up_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_tos_quick_rotate_down_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tos_quick_rotate_down_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_tos_quick_no_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tos_quick_no_rotate_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_tob_merge_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tob_merge_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_tob_quick_no_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tob_quick_no_rotate_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

t_err					ps_solve_tob_quick_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							size_t length,
							bool from_right);
size_t					ps_solve_tob_quick_rotate_count(
							t_ps_solve_context *context,
							int *arr,
							size_t length);

#endif
