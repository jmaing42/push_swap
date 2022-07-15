/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_tst_internal.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 00:02:22 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/16 00:14:55 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SOLVE_TST_INTERNAL_H
# define PS_SOLVE_TST_INTERNAL_H

# include "ps_solve_internal.h"

t_err	ps_solve_tst_merge_no_rotate_solve(
			t_ps_solve_context *context,
			int *arr,
			size_t length,
			bool from_right);
size_t	ps_solve_tst_merge_no_rotate_count(
			t_ps_solve_context *context,
			int *arr,
			size_t length);

t_err	ps_solve_tst_merge_rotate_zy_solve(
			t_ps_solve_context *context,
			int *arr,
			size_t length,
			bool from_right);
size_t	ps_solve_tst_merge_rotate_zy_count(
			t_ps_solve_context *context,
			int *arr,
			size_t length);

t_err	ps_solve_tst_merge_rotate_yx_solve(
			t_ps_solve_context *context,
			int *arr,
			size_t length,
			bool from_right);
size_t	ps_solve_tst_merge_rotate_yx_count(
			t_ps_solve_context *context,
			int *arr,
			size_t length);

t_err	ps_solve_tst_quick_no_rotate_solve(
			t_ps_solve_context *context,
			int *arr,
			size_t length,
			bool from_right);
size_t	ps_solve_tst_quick_no_rotate_count(
			t_ps_solve_context *context,
			int *arr,
			size_t length);

t_err	ps_solve_tst_quick_rotate_zy_solve(
			t_ps_solve_context *context,
			int *arr,
			size_t length,
			bool from_right);
size_t	ps_solve_tst_quick_rotate_zy_count(
			t_ps_solve_context *context,
			int *arr,
			size_t length);

t_err	ps_solve_tst_quick_rotate_yx_solve(
			t_ps_solve_context *context,
			int *arr,
			size_t length,
			bool from_right);
size_t	ps_solve_tst_quick_rotate_yx_count(
			t_ps_solve_context *context,
			int *arr,
			size_t length);

#endif
