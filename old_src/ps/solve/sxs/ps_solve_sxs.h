/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_sxs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 05:08:19 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 17:05:27 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SOLVE_SXS_H
# define PS_SOLVE_SXS_H

# include "ps_solve_internal.h"

t_ps_solve_strategy		ps_solve_sxs_strategy(
							const t_ps_solve_context *context,
							size_t count);
t_ps_solve_count_part	ps_solve_sxs_count_part(
							const t_ps_solve_table *table,
							size_t count);

t_err					ps_solve_sxs_merge_straightforward_solve(
							const t_ps_solve_context *context,
							const int *arr,
							t_ps_solve_count_size size,
							bool from_right);
size_t					ps_solve_sxs_merge_straightforward_count(
							const t_ps_solve_table *table,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_sxs_merge_twist_solve(
							const t_ps_solve_context *context,
							const int *arr,
							t_ps_solve_count_size size,
							bool from_right);
size_t					ps_solve_sxs_merge_twist_count(
							const t_ps_solve_table *table,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_sxs_quick_straightforward_solve(
							const t_ps_solve_context *context,
							const int *arr,
							t_ps_solve_count_size size,
							bool from_right);
size_t					ps_solve_sxs_quick_straightforward_count(
							const t_ps_solve_table *table,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_sxs_quick_twist_solve(
							const t_ps_solve_context *context,
							const int *arr,
							t_ps_solve_count_size size,
							bool from_right);
size_t					ps_solve_sxs_quick_twist_count(
							const t_ps_solve_table *table,
							size_t x,
							size_t y,
							size_t z);

#endif
