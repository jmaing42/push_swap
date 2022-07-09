/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_sxs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:55:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 14:57:09 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRATEGY_SXS_H
# define PS_STRATEGY_SXS_H

# include "ps_strategy.h"

void	ps_strategy_sxs_init(
			t_ps_strategy_count *table,
			size_t index);

t_err	ps_strategy_sxs_fallback_txt_execute(
			t_ps_strategy_solve_context *context,
			size_t count,
			int *arr,
			bool from_right);

#endif
