/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_tsb_quick.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 21:26:35 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/08 21:49:51 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRATEGY_TSB_QUICK_H
# define PS_STRATEGY_TSB_QUICK_H

# include "ps_strategy_tsb.h"

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
 * ||    : |              |              |              |              |      ||
 * ||    : |              | z            | z            | z            |      ||
 * ||   -A-+-B-    (1) -A-+-B-    (2) -A-+-B-    (3) -A-+-B-    (4) -A-+-B-   ||
 * ||      |            x | y          X | y          X |            X |      ||
 * ||      |              |              |            Y |            Y |      ||
 * ||                                                                Z        ||
 * ||    (1) divide        (2) sort z        (3) sort y        (4) sort x     ||
 *
 */
size_t	ps_strategy_tsb_quick_count(
			const t_ps_strategy_count *table,
			size_t x,
			size_t y,
			size_t z);

void	ps_strategy_tsb_quick_count_init_if_better(
			t_ps_strategy_count *table,
			size_t index);

t_err	ps_strategy_tsb_quick_execute(
			t_ps_strategy_solve_context *context,
			size_t count,
			int *arr,
			bool from_right);

#endif
