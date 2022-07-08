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

size_t	ps_strategy_tst_count_m1(
			const t_ps_strategy_count *table,
			size_t x,
			size_t y,
			size_t z);
size_t	ps_strategy_tst_count_m2(
			const t_ps_strategy_count *table,
			size_t x,
			size_t y,
			size_t z);
size_t	ps_strategy_tst_count_q1(
			const t_ps_strategy_count *table,
			size_t x,
			size_t y,
			size_t z);
size_t	ps_strategy_tst_count_q2(
			const t_ps_strategy_count *table,
			size_t x,
			size_t y,
			size_t z);

#endif
