/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_tst.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 05:08:19 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/18 05:40:31 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SOLVE_TST_H
# define PS_SOLVE_TST_H

# include "ps_solve_internal.h"

t_ps_solve_strategy		ps_solve_tst_strategy(size_t count);
t_ps_solve_count_part	ps_solve_tst_count_part(size_t count);

t_err					ps_solve_tst_merge_no_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							t_ps_solve_count_size size,
							bool from_right);
size_t					ps_solve_tst_merge_no_rotate_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_tst_merge_early_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							t_ps_solve_count_size size,
							bool from_right);
size_t					ps_solve_tst_merge_early_rotate_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_tst_merge_late_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							t_ps_solve_count_size size,
							bool from_right);
size_t					ps_solve_tst_merge_late_rotate_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_tst_quick_no_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							t_ps_solve_count_size size,
							bool from_right);
size_t					ps_solve_tst_quick_no_rotate_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_tst_quick_early_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							t_ps_solve_count_size size,
							bool from_right);
size_t					ps_solve_tst_quick_early_rotate_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_tst_quick_late_rotate_solve(
							t_ps_solve_context *context,
							int *arr,
							t_ps_solve_count_size size,
							bool from_right);
size_t					ps_solve_tst_quick_late_rotate_count(
							t_ps_solve_context *context,
							size_t x,
							size_t y,
							size_t z);

#endif
