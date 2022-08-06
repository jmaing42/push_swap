/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_count_sob.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 22:43:59 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/06 22:47:24 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

size_t	ps_solve_util_count_sob(
	const t_ps_solve_context *context,
	size_t index
)
{
	return (context->table[index].sob.item.count);
}
