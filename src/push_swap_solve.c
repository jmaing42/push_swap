/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 01:54:20 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/20 02:14:16 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solve_internal.h"

#include <stdlib.h>

#include "ft_memory.h"
#include "ft_exit.h"

void	push_swap_solve(t_push_swap *self, const int *arr, size_t count)
{
	int *const	copy = (int *)ft_memdup(arr, sizeof(int) * count);

	if (!copy)
		ft_exit(EXIT_FAILURE);
	push_swap_solve_internal_sort_only(self, copy, count, false);
	free(copy);
}
// TODO: use special solution
