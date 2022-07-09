/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_tob.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:42:48 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 12:43:02 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRATEGY_TOB_H
# define PS_STRATEGY_TOB_H

# include "ps_strategy.h"

void	ps_strategy_tob_init(
			t_ps_strategy_count *table,
			size_t index);

t_err	ps_strategy_tob_fallback_tot_execute(
			t_ps_strategy_solve_context *context,
			size_t count,
			int *arr,
			bool from_right);

#endif
