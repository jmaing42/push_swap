/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_sss.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 05:08:19 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 16:58:12 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SOLVE_SSS_H
# define PS_SOLVE_SSS_H

# include "ps_solve_internal.h"

t_ps_solve_strategy		ps_solve_sss_strategy(
							const t_ps_solve_context *context,
							size_t count);
t_ps_solve_count_part	ps_solve_sss_count_part(
							const t_ps_solve_table *table,
							size_t count);

t_err					ps_solve_sss_merge_solve(
							const t_ps_solve_context *context,
							const int *arr,
							t_ps_solve_count_size size,
							bool from_right);
size_t					ps_solve_sss_merge_count(
							const t_ps_solve_table *table,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_sss_quick_solve(
							const t_ps_solve_context *context,
							const int *arr,
							t_ps_solve_count_size size,
							bool from_right);
size_t					ps_solve_sss_quick_count(
							const t_ps_solve_table *table,
							size_t x,
							size_t y,
							size_t z);

#endif
