/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_array_sort_as.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 08:48:52 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/07 16:19:01 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include "ft_types_primitive_int.h"

void	ps_solve_util_array_sort_as(
	t_ps_solve_util_array_mutable *self,
	const int *order_array,
	size_t order_length
)
{
	size_t	i;
	size_t	j;
	size_t	index;
	bool	in_self;

	index = 0;
	i = -1;
	while (++i < order_length)
	{
		in_self = false;
		j = index - 1;
		while (++j < self->length && !in_self)
		{
			if (order_array[i] == self->array[j])
			{
				in_self = true;
				ft_types_primitive_int_swap(
					&self->array[j],
					&self->array[index++]);
			}
		}
	}
}
