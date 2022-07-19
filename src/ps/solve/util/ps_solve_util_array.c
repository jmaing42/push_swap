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

void	ps_solve_util_array_sort(
	t_ps_solve_util_array	*array
)
{
	size_t	i;
	size_t	j;
	int		tmp;

	if (!array->length)
		return ;
	i = -1;
	while (++i < array->length - 1)
	{
		j = i;
		while (++j < array->length)
		{
			if (array->array[i] > array->array[j])
			{
				tmp = array->array[i];
				array->array[i] = array->array[j];
				array->array[j] = tmp;
			}
		}
	}
}

void	ps_solve_util_array_inverse(
	t_ps_solve_util_array	*array
)
{
	size_t	i;

	i = -1;
	while (++i < array->length)
		array->array[i] = ~array->array[i];
}

void	ps_solve_util_array_reverse(
	t_ps_solve_util_array	*array
)
{
	const size_t	to = array->length / 2;
	size_t			i;
	int				tmp;

	i = -1;
	while (++i < to)
	{
		tmp = array->array[array->length - i - 1];
		array->array[array->length - i - 1] = array->array[i];
		array->array[i] = tmp;
	}
}
