/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_internal_sort.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:53:35 by jmaing            #+#    #+#             */
/*   Updated: 2022/06/04 16:30:53 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solve_internal.h"

void	push_swap_solve_internal_sort(
	int *ptr,
	size_t length,
	bool reverse_order
)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = -1;
	while (++i < length - 1)
	{
		j = i;
		while (++j < length)
		{
			if (ptr[i] < ptr[j] == reverse_order)
			{
				tmp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = tmp;
			}
		}
	}
}
