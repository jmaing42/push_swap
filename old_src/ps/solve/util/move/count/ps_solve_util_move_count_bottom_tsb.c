/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_move_count_bottom_tsb.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 14:40:47 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 14:45:52 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

size_t	ps_solve_util_move_count_bottom_tsb(
	size_t x,
	size_t y,
	size_t z
)
{
	return (2 * x + y + 3 * z);
}
