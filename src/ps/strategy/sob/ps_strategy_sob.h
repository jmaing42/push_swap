/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_sob.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:34:32 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 16:36:12 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRATEGY_SOB_H
# define PS_STRATEGY_SOB_H

# include "ps_strategy.h"

void	ps_strategy_sob_init(
			t_ps_strategy_count *table,
			size_t index);

t_err	ps_strategy_sob_fallback_tob_execute(
			t_ps_strategy_solve_context *context,
			size_t count,
			int *arr,
			bool from_right);

#endif
