/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_sss_quick.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:47:57 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 14:50:00 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRATEGY_SSS_QUICK_H
# define PS_STRATEGY_SSS_QUICK_H

# include "ps_strategy_tob.h"

/**
 * @brief calculate maximum operation count to sort with quick sort like way
 *
 * @param map array containing previous operation count   (bottom-up DP)
 * @param x count of smallest part
 * @param y count of medium part
 * @param z count of biggest part
 * @return size_t maximum operation count to sort given arguments
 *
 * ||    :                                                                    ||
 * ||    :                                                           X        ||
 * ||    : |              |              |            Y |            Y |      ||
 * ||      |            Z | x          Z | x          Z | x          Z |      ||
 * ||      +-B-    (1)    +-B-    (2)    +-B-    (3)    +-B-    (4)    +-B-   ||
 * ||      |              | y            | y            |              |      ||
 * ||      |              |              |              |              |      ||
 * ||                                                                         ||
 * ||    (1) divide        (2) sort z        (3) sort y        (4) sort x     ||
 *
 */
size_t	ps_strategy_sss_quick_count(
			const t_ps_strategy_count *table,
			size_t x,
			size_t y,
			size_t z);

void	ps_strategy_sss_quick_count_init_if_better(
			t_ps_strategy_count *table,
			size_t index);

t_err	ps_strategy_sss_quick_execute(
			t_ps_strategy_solve_context *context,
			size_t count,
			int *arr,
			bool from_right);

#endif
