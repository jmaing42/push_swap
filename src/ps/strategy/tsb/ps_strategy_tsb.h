/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_tsb.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 21:28:16 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 00:23:10 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRATEGY_TSB_H
# define PS_STRATEGY_TSB_H

# include "ps_strategy.h"

void	ps_strategy_tsb_init(
			t_ps_strategy_count *table,
			size_t index);

t_err	ps_strategy_tsb_fallback_tst_execute(
			t_ps_strategy_solve_context *context,
			size_t count,
			int *arr,
			bool from_right);

#endif