/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_tob_quick_rotate.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:57:01 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 12:59:20 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRATEGY_TOB_QUICK_ROTATE_H
# define PS_STRATEGY_TOB_QUICK_ROTATE_H

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
 * ||                                                                         ||
 * ||    :                                                                    ||
 * ||    : |           |           | x         |           |           |      ||
 * ||    : |           | z       y | z       y | z         | z         |      ||
 * ||   -A-+-B- (1) -A-+-B- (2) -A-+-B- (3) -A-+-B- (4) -A-+-B- (5) -A-+-B-   ||
 * ||      |         y | x         |           | X         | X         | X    ||
 * ||      |           |           |           |           | Y         | Y    ||
 * ||                                                                    Z    ||
 * ||   (1) divide    (2) rotate    (3) sort x    (4) sort y    (5) sort z    ||
 *
 */
size_t	ps_strategy_tob_quick_rotate_count(
			const t_ps_strategy_count *table,
			size_t x,
			size_t y,
			size_t z);

void	ps_strategy_tob_quick_rotate_count_init_if_better(
			t_ps_strategy_count *table,
			size_t index);

t_err	ps_strategy_tob_quick_rotate_execute(
			t_ps_strategy_solve_context *context,
			size_t count,
			int *arr,
			bool from_right);

#endif
