/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_internal_inverse.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:05:03 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/11 21:05:24 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solve_internal.h"

void	push_swap_sort_internal_inverse(
	int *ptr,
	size_t length
)
{
	const size_t	to = length / 2;
	size_t			i;

	i = -1;
	while (++i < to)
		ptr[i] = ~ptr[i];
}
