/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_internal_inverse.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:05:03 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/14 01:40:30 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solve_internal.h"

void	push_swap_solve_internal_inverse(
	int *ptr,
	size_t length
)
{
	size_t			i;

	i = -1;
	while (++i < length)
		ptr[i] = ~ptr[i];
}
