/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_part_operation_swap.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:29:37 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/30 00:10:50 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

void	ps_stack_part_operation_swap(t_ps_stack_part *self)
{
	const size_t	offset = (self->offset + 1) % self->capacity;
	int				tmp;

	if (self->size <= 1)
		return ;
	tmp = self->arr[offset];
	self->arr[offset] = self->arr[self->offset];
	self->arr[self->offset] = tmp;
}
