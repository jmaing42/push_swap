/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy_bst.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:41:55 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/09 17:49:14 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRATEGY_BST_H
# define PS_STRATEGY_BST_H

# include "ps_strategy.h"

void	ps_strategy_bst_init(
			t_ps_strategy_count *table,
			size_t index);

t_err	ps_strategy_bst_fallback_tst_execute(
			t_ps_strategy_solve_context *context,
			size_t count,
			int *arr,
			bool from_right);

#endif
