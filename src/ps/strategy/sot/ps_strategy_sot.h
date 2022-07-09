/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_sot.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:15:11 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 16:19:27 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRATEGY_SOT_H
# define PS_STRATEGY_SOT_H

# include "ps_strategy.h"

void	ps_strategy_sot_init(
			t_ps_strategy_count *table,
			size_t index);

t_err	ps_strategy_sot_fallback_tot_execute(
			t_ps_strategy_solve_context *context,
			size_t count,
			int *arr,
			bool from_right);

#endif
