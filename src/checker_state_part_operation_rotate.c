/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_state_part_operation_rotate.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:29:37 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/11 21:50:39 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_state.h"

void	checker_state_part_operation_rotate(t_checker_state_part *self)
{
	const int	tmp = self->arr[self->offset];

	if (self->size <= 1)
		return ;
	self->offset = (self->offset + 1) % self->capacity;
	self->arr[(self->offset + self->size - 1) % self->capacity] = tmp;
}
