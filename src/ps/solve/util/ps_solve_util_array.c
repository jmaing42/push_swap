/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:12:25 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/19 09:15:07 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

void	ps_solve_util_sort(
	int *array,
	size_t length
)
{
	size_t	i;
	size_t	j;
	int		tmp;

	if (!length)
		return ;
	i = -1;
	while (++i < length - 1)
	{
		j = i;
		while (++j < length)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}

void	ps_solve_util_array_sort(
	t_ps_solve_util_array *self
)
{
	ps_solve_util_sort(self->array, self->length);
}

void	ps_solve_util_array_inverse(
	t_ps_solve_util_array *self
)
{
	size_t	i;

	i = -1;
	while (++i < self->length)
		self->array[i] = ~self->array[i];
}

void	ps_solve_util_array_reverse(
	t_ps_solve_util_array *self
)
{
	const size_t	to = self->length / 2;
	size_t			i;
	int				tmp;

	i = -1;
	while (++i < to)
	{
		tmp = self->array[self->length - i - 1];
		self->array[self->length - i - 1] = self->array[i];
		self->array[i] = tmp;
	}
}
