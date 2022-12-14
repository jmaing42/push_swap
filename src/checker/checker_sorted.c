/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 00:01:12 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/14 00:57:08 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

bool	checker_sorted(t_ps_stack *self)
{
	size_t	i;

	if (self->b.size != 0)
		return (false);
	i = 0;
	while (++i < self->a.size)
		if (
			self->a.arr[
				(self->a.offset + i - 1 + self->a.capacity) % self->a.capacity
			] > self->a.arr[
				(self->a.offset + i) % self->a.capacity
			]
		)
			return (false);
	return (true);
}
