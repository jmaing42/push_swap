/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_array_inverse.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:44:42 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 08:30:41 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

void	ps_solve_util_array_inverse(
	t_ps_solve_util_array_mutable *self
)
{
	size_t	i;

	i = -1;
	while (++i < self->length)
		self->array[i] = ~self->array[i];
}
