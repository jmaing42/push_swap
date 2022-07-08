/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:45:05 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/08 09:28:52 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRATEGY_UTIL_H
# define PS_STRATEGY_UTIL_H

# include <stddef.h>

# include "ps_strategy.h"

t_ps_strategy_count_item	ps_strategy_util_try_all_permutations(
								t_ps_strategy_count *table,
								size_t count,
								size_t (*calculate_with_exact_count)(
									const t_ps_strategy_count *table,
									size_t x,
									size_t y,
									size_t z));

#endif
