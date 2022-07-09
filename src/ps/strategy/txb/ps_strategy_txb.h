/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_txb.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 09:24:31 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 09:33:55 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRATEGY_TXB_H
# define PS_STRATEGY_TXB_H

# include "ps_strategy.h"

void	ps_strategy_txb_init(
			t_ps_strategy_count *table,
			size_t index);

t_err	ps_strategy_txb_fallback_txt_execute(
			t_ps_strategy_solve_context *context,
			size_t count,
			int *arr,
			bool from_right);

#endif
