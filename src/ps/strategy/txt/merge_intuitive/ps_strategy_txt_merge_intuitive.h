/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_txt_merge_intuitive.h                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 21:26:35 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 00:15:29 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRATEGY_TXT_MERGE_INTUITIVE_H
# define PS_STRATEGY_TXT_MERGE_INTUITIVE_H

# include "ps_strategy_txt.h"

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
 * ||    x                                                           :        ||
 * ||    y |            y |              |              | Z          : |      ||
 * ||    z |            z |            z | Y            | Y          : |      ||
 * ||   -A-+       (1) -A-+       (2) -A-+       (3) -A-+       (4) -A-+      ||
 * ||      |            X |            X |            X |              |      ||
 * ||      | B            | B            | B            | B            | B    ||
 * ||                                                                         ||
 * ||    (1) sort x        (2) sort y        (3) sort z        (4) collect    ||
 *
 */
size_t	ps_strategy_txt_merge_intuitive_count(
			const t_ps_strategy_count *table,
			size_t x,
			size_t y,
			size_t z);

void	ps_strategy_txt_merge_intuitive_count_init_if_better(
			t_ps_strategy_count *table,
			size_t index);

t_err	ps_strategy_txt_merge_intuitive_execute(
			t_ps_strategy_solve_context *context,
			size_t count,
			int *arr,
			bool from_right);

#endif
