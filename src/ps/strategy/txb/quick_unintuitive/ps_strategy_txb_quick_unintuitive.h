/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_txb_quick_unintuitive.h                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 09:41:13 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 09:42:30 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRATEGY_TXB_QUICK_UNINTUITIVE_H
# define PS_STRATEGY_TXB_QUICK_UNINTUITIVE_H

# include "ps_strategy_txb.h"

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
 * ||    : |              | z            | z            | z            |      ||
 * ||    : |              | y            | y            |              |      ||
 * ||   -A-+       (1) -A-+       (2) -A-+       (3) -A-+       (4) -A-+      ||
 * ||      |            x |            X |            X |            X |      ||
 * ||      | B            | B            | B          Y | B          Y | B    ||
 * ||                                                                Z        ||
 * ||    (1) divide        (2) sort x        (3) sort y        (4) sort z     ||
 *
 */
size_t	ps_strategy_txb_quick_unintuitive_count(
			const t_ps_strategy_count *table,
			size_t x,
			size_t y,
			size_t z);

void	ps_strategy_txb_quick_unintuitive_count_init_if_better(
			t_ps_strategy_count *table,
			size_t index);

t_err	ps_strategy_txb_quick_unintuitive_execute(
			t_ps_strategy_solve_context *context,
			size_t count,
			int *arr,
			bool from_right);

#endif
