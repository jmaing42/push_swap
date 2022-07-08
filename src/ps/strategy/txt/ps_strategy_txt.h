/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_txt.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:11:34 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 00:34:46 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRATEGY_TXT_H
# define PS_STRATEGY_TXT_H

# include "ps_strategy.h"

void	ps_strategy_txt_init(
			t_ps_strategy_count *table,
			size_t index);

t_err	ps_strategy_txt_fallback_tst_execute(
			t_ps_strategy_solve_context *context,
			size_t count,
			int *arr,
			bool from_right);

#endif
