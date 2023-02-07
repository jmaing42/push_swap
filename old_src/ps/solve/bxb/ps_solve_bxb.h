/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_bxb.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:21:42 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/06 21:21:43 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SOLVE_BXB_H
# define PS_SOLVE_BXB_H

# include "ps_solve_internal.h"

t_ps_solve_strategy		ps_solve_bxb_strategy(
							const t_ps_solve_context *context,
							size_t count);
t_ps_solve_count_part	ps_solve_bxb_count_part(
							const t_ps_solve_table *table,
							size_t count);

t_err					ps_solve_bxb_merge_straightforward_solve(
							const t_ps_solve_context *context,
							const int *arr,
							t_ps_solve_count_size size,
							bool from_right);
size_t					ps_solve_bxb_merge_straightforward_count(
							const t_ps_solve_table *table,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bxb_merge_twist_solve(
							const t_ps_solve_context *context,
							const int *arr,
							t_ps_solve_count_size size,
							bool from_right);
size_t					ps_solve_bxb_merge_twist_count(
							const t_ps_solve_table *table,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bxb_quick_straightforward_solve(
							const t_ps_solve_context *context,
							const int *arr,
							t_ps_solve_count_size size,
							bool from_right);
size_t					ps_solve_bxb_quick_straightforward_count(
							const t_ps_solve_table *table,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bxb_quick_twist_solve(
							const t_ps_solve_context *context,
							const int *arr,
							t_ps_solve_count_size size,
							bool from_right);
size_t					ps_solve_bxb_quick_twist_count(
							const t_ps_solve_table *table,
							size_t x,
							size_t y,
							size_t z);

#endif
