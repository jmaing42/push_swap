/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_part_operation_reverse_rotate.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:29:37 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/30 00:13:58 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

void	ps_stack_part_operation_reverse_rotate(t_ps_stack_part *self)
{
	const int	tmp
		= self->arr[(self->offset + self->size - 1) % self->capacity];

	if (self->size <= 1)
		return ;
	self->offset = (self->capacity + self->offset - 1) % self->capacity;
	self->arr[self->offset] = tmp;
}
