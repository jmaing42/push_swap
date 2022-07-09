/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_tot_merge_no_rotate.h                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 09:50:43 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 09:52:24 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRATEGY_TOT_MERGE_NO_ROTATE_H
# define PS_STRATEGY_TOT_MERGE_NO_ROTATE_H

# include "ps_strategy_tot.h"

/**
 * @brief calculate maximum operation count to sort with merge sort like way
 *
 * @param map array containing previous operation count   (bottom-up DP)
 * @param x count of first part
 * @param y count of second part
 * @param z count of third part
 * @return size_t maximum operation count to sort given arguments
 *
 * ||                                                                         ||
 * ||    x                                                               :    ||
 * ||    y |            y |              |              |              | :    ||
 * ||    z |            z |            z |            Z |              | :    ||
 * ||   -A-+-B-    (1) -A-+-B-    (2) -A-+-B-    (3) -A-+-B-    (4) -A-+-B-   ||
 * ||      |              | X          Y | X          Y | X            |      ||
 * ||      |              |              |              |              |      ||
 * ||                                                                         ||
 * ||    (1) sort x        (2) sort y        (3) sort z        (4) collect    ||
 *
 */
size_t	ps_strategy_tot_merge_no_rotate_count(
			const t_ps_strategy_count *table,
			size_t x,
			size_t y,
			size_t z);

void	ps_strategy_tot_merge_no_rotate_count_init_if_better(
			t_ps_strategy_count *table,
			size_t index);

t_err	ps_strategy_tot_merge_no_rotate_execute(
			t_ps_strategy_solve_context *context,
			size_t count,
			int *arr,
			bool from_right);

#endif
