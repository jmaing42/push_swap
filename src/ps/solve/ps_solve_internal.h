/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:31:49 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/17 00:50:08 by Juyeong Maing    ###   ########.fr       */
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

t_err					ps_solve_util_move_tst(
							t_ps_stream *stream,
							bool from_right);
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
t_err					ps_solve_util_move_bsb(
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

#endif
