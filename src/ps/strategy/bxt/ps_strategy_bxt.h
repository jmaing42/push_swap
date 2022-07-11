/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_bxt.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 08:51:05 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/10 08:51:26 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRATEGY_BXT_H
# define PS_STRATEGY_BXT_H

# include "ps_strategy.h"

void	ps_strategy_bxt_init(
			t_ps_strategy_count *table,
			size_t index);

t_err	ps_strategy_bxt_fallback_txt_execute(
			t_ps_strategy_solve_context *context,
			size_t count,
			int *arr,
			bool from_right);

#endif
