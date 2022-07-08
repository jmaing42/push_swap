/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_txt_quick_unintuitive.h                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 21:26:35 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 00:31:56 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRATEGY_TXT_QUICK_UNINTUITIVE_H
# define PS_STRATEGY_TXT_QUICK_UNINTUITIVE_H

# include "ps_strategy_txt.h"

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
 * ||    :                                                           X        ||
 * ||    : |              | y            | y          Y |            Y |      ||
 * ||    : |              | z          Z |            Z |            Z |      ||
 * ||   -A-+       (1) -A-+       (2) -A-+       (3) -A-+       (4) -A-+      ||
 * ||      |            x |            x |            x |              |      ||
 * ||      | B            | B            | B            | B            | B    ||
 * ||                                                                         ||
 * ||    (1) divide        (2) sort z        (3) sort y        (4) sort x     ||
 *
 */
size_t	ps_strategy_txt_quick_unintuitive_count(
			const t_ps_strategy_count *table,
			size_t x,
			size_t y,
			size_t z);

void	ps_strategy_txt_quick_unintuitive_count_init_if_better(
			t_ps_strategy_count *table,
			size_t index);

t_err	ps_strategy_txt_quick_unintuitive_execute(
			t_ps_strategy_solve_context *context,
			size_t count,
			int *arr,
			bool from_right);

#endif
