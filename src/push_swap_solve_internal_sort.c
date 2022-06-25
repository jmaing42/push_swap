/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_internal_sort.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:53:35 by jmaing            #+#    #+#             */
/*   Updated: 2022/06/26 01:51:25 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solve_internal.h"

#include "ft_memory.h"
#include "ft_malloc.h"

void	push_swap_solve_internal_sort(
	int *ptr,
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
			if (ptr[i] > ptr[j])
			{
				tmp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = tmp;
			}
		}
	}
}

int	*push_swap_solve_internal_sorted(
	int *arr,
	size_t length
)
{
	int *const	result
		= (int *)ft_nonnull(ft_memdup(arr, sizeof(int) * length));

	push_swap_solve_internal_sort(result, length);
	return (result);
}
