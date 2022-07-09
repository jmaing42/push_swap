/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_bsb.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:10:10 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 18:20:23 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRATEGY_BSB_H
# define PS_STRATEGY_BSB_H

# include "ps_strategy.h"

void	ps_strategy_bsb_init(
			t_ps_strategy_count *table,
			size_t index);

t_err	ps_strategy_bsb_fallback_tsb_execute(
			t_ps_strategy_solve_context *context,
			size_t count,
			int *arr,
			bool from_right);

#endif
