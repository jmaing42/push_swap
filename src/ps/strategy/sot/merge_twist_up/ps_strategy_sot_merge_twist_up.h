/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_sot_merge_twist_up.h                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:38:49 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 17:12:07 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRATEGY_SOT_MERGE_TWIST_UP_H
# define PS_STRATEGY_SOT_MERGE_TWIST_UP_H

# include "ps_strategy_sot.h"

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
 * ||                                                                    :    ||
 * ||    x |              |              |            Z |              | :    ||
 * ||    y |            y |            Y |            Y |              | :    ||
 * ||    z +-B-    (1)  z +-B-    (2)  z +-B-    (3)    +-B-    (4)    +-B-   ||
 * ||      |              | X            | X            | X            |      ||
 * ||    A |            A |            A |            A |            A |      ||
 * ||                                                                         ||
 * ||    (1) sort x        (2) sort y        (3) sort z        (4) collect    ||
 *
 */
size_t	ps_strategy_sot_merge_twist_up_count(
			const t_ps_strategy_count *table,
			size_t x,
			size_t y,
			size_t z);

void	ps_strategy_sot_merge_twist_up_count_init_if_better(
			t_ps_strategy_count *table,
			size_t index);

t_err	ps_strategy_sot_merge_twist_up_execute(
			t_ps_strategy_solve_context *context,
			size_t count,
			int *arr,
			bool from_right);

#endif
