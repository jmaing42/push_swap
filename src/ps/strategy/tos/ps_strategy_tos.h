/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_tos.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 10:20:55 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 10:21:07 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRATEGY_TOS_H
# define PS_STRATEGY_TOS_H

# include "ps_strategy.h"

void	ps_strategy_tos_init(
			t_ps_strategy_count *table,
			size_t index);

t_err	ps_strategy_tos_fallback_tot_execute(
			t_ps_strategy_solve_context *context,
			size_t count,
			int *arr,
			bool from_right);

#endif
