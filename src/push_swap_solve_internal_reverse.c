/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_internal_reverse.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:53:35 by jmaing            #+#    #+#             */
/*   Updated: 2022/06/04 18:24:35 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solve_internal.h"

void	push_swap_sort_internal_reverse(
	int *ptr,
	size_t length
)
{
	const size_t	to = length / 2;
	size_t			i;
	int				tmp;

	i = -1;
	while (++i < to)
	{
		tmp = ptr[length - i - 1];
		ptr[length - i - 1] = ptr[i];
		ptr[i] = tmp;
	}
}
