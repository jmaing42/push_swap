/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 01:54:20 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/10 17:22:28 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solve_internal.h"

#include <stdlib.h>

#include "ft_memory.h"
#include "ft_exit.h"

#include "ps_hardcoded.h"

static bool	hardcoded(const int *arr, size_t count)
{
	const char *const	*table;
	size_t				dummy;

	if (count < 3)
		ps_hardcoded_sxs_2(&table, &dummy);
	if (count == 3)
		ps_hardcoded_sxs_3(&table, &dummy);
	if (count == 4)
		ps_hardcoded_sxs_4(&table, &dummy);
	if (count == 5)
		ps_hardcoded_sxs_5(&table, &dummy);
	if (count == 6)
		ps_hardcoded_sxs_6(&table, &dummy);
	if (count == 7)
		ps_hardcoded_sxs_7(&table, &dummy);
	if (count == 8)
		ps_hardcoded_sxs_8(&table, &dummy);
	ps_hardcoded_execute(ps_hardcoded_find_index(arr, count), false, table);
	return (true);
}

void	push_swap_solve(t_push_swap *self, const int *arr, size_t count)
{
	int *const	copy = (int *)ft_memdup(arr, sizeof(int) * count);

	if (!copy)
		ft_exit(EXIT_FAILURE);
	if (hardcoded(arr, count))
	{
		free(copy);
		return ;
	}
	push_swap_solve_sort_only(self, copy, count, false);
	free(copy);
}
