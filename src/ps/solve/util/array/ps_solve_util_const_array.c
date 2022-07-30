/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_const_array.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 21:08:39 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/30 21:55:04 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

t_ps_solve_util_const_array	ps_solve_util_const_array(
	const int *self,
	size_t length
)
{
	const t_ps_solve_util_const_array	result = {
		self,
		length
	};

	return (result);
}
