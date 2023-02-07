/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_bob.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 22:03:11 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/06 22:03:11 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SOLVE_BOB_H
# define PS_SOLVE_BOB_H

# include "ps_solve_internal.h"

t_ps_solve_strategy		ps_solve_bob_strategy(
							const t_ps_solve_context *context,
							size_t count);
t_ps_solve_count_part	ps_solve_bob_count_part(
							const t_ps_solve_table *table,
							size_t count);

t_err					ps_solve_bob_merge_solve(
							const t_ps_solve_context *context,
							const int *arr,
							t_ps_solve_count_size size,
							bool from_right);
size_t					ps_solve_bob_merge_count(
							const t_ps_solve_table *table,
							size_t x,
							size_t y,
							size_t z);

t_err					ps_solve_bob_quick_solve(
							const t_ps_solve_context *context,
							const int *arr,
							t_ps_solve_count_size size,
							bool from_right);
size_t					ps_solve_bob_quick_count(
							const t_ps_solve_table *table,
							size_t x,
							size_t y,
							size_t z);

#endif
