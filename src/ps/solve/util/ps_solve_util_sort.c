/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_sort.c                               :+:      :+:    :+:   */
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
