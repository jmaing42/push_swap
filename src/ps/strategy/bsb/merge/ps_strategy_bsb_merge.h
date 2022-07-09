/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_bsb_merge.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:59:06 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 18:19:50 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRATEGY_BSB_MERGE_H
# define PS_STRATEGY_BSB_MERGE_H

# include "ps_strategy_bsb.h"

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
 * ||                                                                         ||
 * ||      |              |              |              |              |      ||
 * ||      |              |              | Y          X | Y            |      ||
 * ||   -A-+-B-    (1) -A-+-B-    (2) -A-+-B-    (3) -A-+-B-    (4) -A-+-B-   ||
 * ||    x |            x | Z          x | Z            | Z          : |      ||
 * ||    y |            y |              |              |            : |      ||
 * ||    z                                                           :        ||
 * ||    (1) sort z        (2) sort y        (3) sort x        (4) collect    ||
 *
 */
size_t	ps_strategy_bsb_merge_count(
			const t_ps_strategy_count *table,
			size_t x,
			size_t y,
			size_t z);

void	ps_strategy_bsb_merge_count_init_if_better(
			t_ps_strategy_count *table,
			size_t index);

t_err	ps_strategy_bsb_merge_execute(
			t_ps_strategy_solve_context *context,
			size_t count,
			int *arr,
			bool from_right);

#endif
