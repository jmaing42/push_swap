/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_state_part_operation_pop.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:29:37 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/19 20:18:07 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_state.h"

bool	checker_state_part_operation_pop(t_checker_state_part *self, int *out)
{
	if (!self->size)
		return (false);
	*out = self->arr[self->offset];
	self->offset = (self->offset + 1) % self->capacity;
	self->size--;
	return (true);
}
