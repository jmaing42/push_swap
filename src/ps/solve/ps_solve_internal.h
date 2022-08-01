/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:31:49 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/01 22:58:19 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SOLVE_INTERNAL_H
# define PS_SOLVE_INTERNAL_H

# include "ps_solve.h"

# include "ft_types.h"

typedef size_t	(*t_ps_solve_count)(
					const t_ps_solve_table *context,
					size_t x,
					size_t y,
					size_t z);

typedef struct s_ps_solve_count_tuple
{
	const t_ps_solve		solver;
	const t_ps_solve_count	counter;
}	t_ps_solve_count_tuple;

typedef struct s_ps_solve_util_array
{
	const int	*array;
	size_t		length;
}	t_ps_solve_util_array;

typedef struct s_ps_solve_util_array_mutable
{
	int		*array;
	size_t	length;
}	t_ps_solve_util_array_mutable;

typedef struct s_ps_solve_util_parts
{
	t_ps_solve_util_array	a;
	t_ps_solve_util_array	b;
	t_ps_solve_util_array	c;
	t_ps_solve_util_array	x;
	t_ps_solve_util_array	y;
	t_ps_solve_util_array	z;
	const int				*original;
	int						memory[];
}	t_ps_solve_util_parts;

typedef struct s_ps_solve_util
{
	t_ps_stream					*stream;
	const t_ps_solve_util_array	*p;
	const t_ps_solve_util_array	*q;
	const t_ps_solve_util_array	*r;
	const int					*array;
	bool						from_right;
}	t_ps_solve_util_input;

typedef struct s_ps_solve_strategy
{
	t_ps_solve_count_size	size;
	t_ps_solve				solve;
}	t_ps_solve_strategy;

t_ps_solve_count_part	ps_solve_util_count_part(
							const t_ps_solve_table *table,
							const t_ps_solve_count_tuple *strategies,
							size_t length,
							size_t count);
t_ps_solve_count_item	ps_solve_util_try_all_permutation(
							const t_ps_solve_table *table,
							const t_ps_solve_count strategy,
							size_t count);

void					ps_solve_util_sort(
							int	*array,
							size_t length);

t_ps_solve_util_array	ps_solve_util_array(
							const int *self,
							size_t length);
void					ps_solve_util_array_sort(
							t_ps_solve_util_array_mutable	*self);
void					ps_solve_util_array_sort_as(
							t_ps_solve_util_array_mutable	*self,
							const int *order_array,
							size_t order_length);
void					ps_solve_util_array_inverse(
							t_ps_solve_util_array_mutable	*self);
void					ps_solve_util_array_reverse(
							t_ps_solve_util_array_mutable	*self);

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
							const t_ps_solve_util_input params);
t_err					ps_solve_util_collect_to_bottom(
							const t_ps_solve_util_input params);
t_err					ps_solve_util_divide_from_top(
							const t_ps_solve_util_input params);
t_err					ps_solve_util_divide_from_bottom(
							const t_ps_solve_util_input params);
t_err					ps_solve_util_rotate_up(
							const t_ps_solve_context *context,
							const t_ps_solve_util_array *left,
							const t_ps_solve_util_array *right,
							bool from_right);
t_err					ps_solve_util_rotate_down(
							const t_ps_solve_context *context,
							const t_ps_solve_util_array *left,
							const t_ps_solve_util_array *right,
							bool from_right);

t_ps_solve_util_parts	*ps_solve_util_allocate_collect(
							const int *array,
							t_ps_solve_count_size size);
t_ps_solve_util_parts	*ps_solve_util_allocate_divide(
							const int *array,
							t_ps_solve_count_size size);

t_err					ps_solve_util_solve_tst(
							const t_ps_solve_context *context,
							t_ps_solve_util_array *array,
							bool from_right,
							bool reverse);
t_err					ps_solve_util_solve_tsb(
							const t_ps_solve_context *context,
							t_ps_solve_util_array *array,
							bool from_right,
							bool reverse);
t_err					ps_solve_util_solve_txt(
							const t_ps_solve_context *context,
							t_ps_solve_util_array *array,
							bool from_right,
							bool reverse);
t_err					ps_solve_util_solve_txb(
							const t_ps_solve_context *context,
							t_ps_solve_util_array *array,
							bool from_right,
							bool reverse);
t_err					ps_solve_util_solve_tot(
							const t_ps_solve_context *context,
							t_ps_solve_util_array *array,
							bool from_right,
							bool reverse);
t_err					ps_solve_util_solve_tos(
							const t_ps_solve_context *context,
							t_ps_solve_util_array *array,
							bool from_right,
							bool reverse);
t_err					ps_solve_util_solve_tob(
							const t_ps_solve_context *context,
							t_ps_solve_util_array *array,
							bool from_right,
							bool reverse);
t_err					ps_solve_util_solve_sss(
							const t_ps_solve_context *context,
							t_ps_solve_util_array *array,
							bool from_right,
							bool reverse);
t_err					ps_solve_util_solve_sxs(
							const t_ps_solve_context *context,
							t_ps_solve_util_array *array,
							bool from_right,
							bool reverse);
t_err					ps_solve_util_solve_sot(
							const t_ps_solve_context *context,
							t_ps_solve_util_array *array,
							bool from_right,
							bool reverse);
t_err					ps_solve_util_solve_sos(
							const t_ps_solve_context *context,
							t_ps_solve_util_array *array,
							bool from_right,
							bool reverse);
t_err					ps_solve_util_solve_sob(
							const t_ps_solve_context *context,
							t_ps_solve_util_array *array,
							bool from_right,
							bool reverse);
t_err					ps_solve_util_solve_bst(
							const t_ps_solve_context *context,
							t_ps_solve_util_array *array,
							bool from_right,
							bool reverse);
t_err					ps_solve_util_solve_bsb(
							const t_ps_solve_context *context,
							t_ps_solve_util_array *array,
							bool from_right,
							bool reverse);
t_err					ps_solve_util_solve_bxt(
							const t_ps_solve_context *context,
							t_ps_solve_util_array *array,
							bool from_right,
							bool reverse);
t_err					ps_solve_util_solve_bxb(
							const t_ps_solve_context *context,
							t_ps_solve_util_array *array,
							bool from_right,
							bool reverse);
t_err					ps_solve_util_solve_bot(
							const t_ps_solve_context *context,
							t_ps_solve_util_array *array,
							bool from_right,
							bool reverse);
t_err					ps_solve_util_solve_bos(
							const t_ps_solve_context *context,
							t_ps_solve_util_array *array,
							bool from_right,
							bool reverse);
t_err					ps_solve_util_solve_bob(
							const t_ps_solve_context *context,
							t_ps_solve_util_array *array,
							bool from_right,
							bool reverse);

size_t					ps_solve_util_move_count_top_stb(
							size_t x,
							size_t y,
							size_t z);
size_t					ps_solve_util_move_count_top_sbt(
							size_t x,
							size_t y,
							size_t z);
size_t					ps_solve_util_move_count_top_tsb(
							size_t x,
							size_t y,
							size_t z);
size_t					ps_solve_util_move_count_top_tbs(
							size_t x,
							size_t y,
							size_t z);
size_t					ps_solve_util_move_count_top_bst(
							size_t x,
							size_t y,
							size_t z);
size_t					ps_solve_util_move_count_top_bts(
							size_t x,
							size_t y,
							size_t z);
size_t					ps_solve_util_move_count_bottom_stb(
							size_t x,
							size_t y,
							size_t z);
size_t					ps_solve_util_move_count_bottom_sbt(
							size_t x,
							size_t y,
							size_t z);
size_t					ps_solve_util_move_count_bottom_tsb(
							size_t x,
							size_t y,
							size_t z);
size_t					ps_solve_util_move_count_bottom_tbs(
							size_t x,
							size_t y,
							size_t z);
size_t					ps_solve_util_move_count_bottom_bst(
							size_t x,
							size_t y,
							size_t z);
size_t					ps_solve_util_move_count_bottom_bts(
							size_t x,
							size_t y,
							size_t z);
t_ps_solve_util_input	ps_solve_util_input_stb(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_ps_solve_util_input	ps_solve_util_input_sbt(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_ps_solve_util_input	ps_solve_util_input_tsb(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_ps_solve_util_input	ps_solve_util_input_tbs(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_ps_solve_util_input	ps_solve_util_input_bst(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_ps_solve_util_input	ps_solve_util_input_bts(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_err					ps_solve_util_collect_to_top_stb(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_err					ps_solve_util_collect_to_top_sbt(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_err					ps_solve_util_collect_to_top_tsb(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_err					ps_solve_util_collect_to_top_tbs(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_err					ps_solve_util_collect_to_top_bst(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_err					ps_solve_util_collect_to_top_bts(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_err					ps_solve_util_collect_to_bottom_stb(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_err					ps_solve_util_collect_to_bottom_sbt(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_err					ps_solve_util_collect_to_bottom_tsb(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_err					ps_solve_util_collect_to_bottom_tbs(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_err					ps_solve_util_collect_to_bottom_bst(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_err					ps_solve_util_collect_to_bottom_bts(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_err					ps_solve_util_divide_from_top_stb(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_err					ps_solve_util_divide_from_top_sbt(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_err					ps_solve_util_divide_from_top_tsb(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_err					ps_solve_util_divide_from_top_tbs(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_err					ps_solve_util_divide_from_top_bst(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_err					ps_solve_util_divide_from_top_bts(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_err					ps_solve_util_divide_from_bottom_stb(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_err					ps_solve_util_divide_from_bottom_sbt(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_err					ps_solve_util_divide_from_bottom_tsb(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_err					ps_solve_util_divide_from_bottom_tbs(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_err					ps_solve_util_divide_from_bottom_bst(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);
t_err					ps_solve_util_divide_from_bottom_bts(
							const t_ps_solve_context *context,
							const t_ps_solve_util_parts *parts,
							bool from_right);

t_ps_solve_util_parts	*ps_solve_util_allocate_divide_stb(
							const int *array,
							t_ps_solve_count_size size);
t_ps_solve_util_parts	*ps_solve_util_allocate_divide_sbt(
							const int *array,
							t_ps_solve_count_size size);
t_ps_solve_util_parts	*ps_solve_util_allocate_divide_tsb(
							const int *array,
							t_ps_solve_count_size size);
t_ps_solve_util_parts	*ps_solve_util_allocate_divide_tbs(
							const int *array,
							t_ps_solve_count_size size);
t_ps_solve_util_parts	*ps_solve_util_allocate_divide_bst(
							const int *array,
							t_ps_solve_count_size size);
t_ps_solve_util_parts	*ps_solve_util_allocate_divide_bts(
							const int *array,
							t_ps_solve_count_size size);

// TODO: move declarations below to each header

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
