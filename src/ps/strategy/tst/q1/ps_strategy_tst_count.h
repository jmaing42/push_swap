/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_tst_count.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:26:26 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/08 09:29:21 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRATEGY_TST_COUNT_H
# define PS_STRATEGY_TST_COUNT_H

# include "ps_strategy_tst.h"

/**
 * @brief calculate maximum operation count to sort with quick sort like way
 *
 * @param map array containing previous operation count   (bottom-up DP)
 * @param x count of small part
 * @param y count of middle part
 * @param z count of big part
 * @return size_t maximum operation count to sort given arguments
 *
 * ||                                                                         ||
 * ||    :                                                           X        ||
 * ||    : |           |           |         y |         Y |         Y |      ||
 * ||    : |           | z       Z |         Z | x       Z | x       Z |      ||
 * ||   -A-+-B- (1) -A-+-B- (2) -A-+-B- (3) -A-+-B- (4) -A-+-B- (5) -A-+-B-   ||
 * ||      |         y | x       y | x         |           |           |      ||
 * ||      |           |           |           |           |           |      ||
 * ||                                                                         ||
 * ||   (1) divide    (2) sort z    (3) rotate    (4) sort y     (5) sort x   ||
 *
 */
size_t	ps_strategy_tst_q1_count(
			const t_ps_strategy_count *table,
			size_t x,
			size_t y,
			size_t z);

#endif
