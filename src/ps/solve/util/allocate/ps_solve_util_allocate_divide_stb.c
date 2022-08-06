/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_allocate_divide_stb.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 23:13:09 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/06 23:13:20 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

t_ps_solve_util_parts	*ps_solve_util_allocate_divide_stb(
	const int *array,
	t_ps_solve_count_size size
)
{
	return (ps_solve_util_allocate_divide(array, size));
}
