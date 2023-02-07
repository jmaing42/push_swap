/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_move_count_bottom_bts.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 14:40:47 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/01 09:04:27 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

size_t	ps_solve_util_move_count_bottom_bts(
	size_t x,
	size_t y,
	size_t z
)
{
	return (3 * x + 2 * y + z);
}
