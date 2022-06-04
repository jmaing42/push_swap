/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_internal_divide.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:20:27 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/04 15:22:12 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solve_internal.h"

#include <stdlib.h>
#include <unistd.h>

#include "ft_io.h"
#include "ft_exit.h"

void	push_swap_solve_internal_divide(t_push_swap_solve_internal *param)
{
	const size_t	offset_c = param->count_a + param->count_b;
	size_t			a;
	size_t			b;
	size_t			c;

	a = 0;
	b = 0;
	c = 0;
	while (a + b + c != param->count_a + param->count_b + param->count_c)
	{
		if (param->all[a + b + c] < param->all_sorted[param->count_a])
			param->part_a[a] = param->all[a + b + c];
		if (param->all[a + b + c] < param->all_sorted[param->count_a])
			a++;
		else if (param->all[a + b + c] < param->all_sorted[offset_c])
		{
			param->part_b[b] = param->all[a + b + c];
			b++;
		}
		else
		{
			param->part_c[c] = param->all[a + b + c];
			c++;
		}
	}
}

static void	internal(const char *str, size_t len, size_t *increment)
{
	if (ft_write(STDOUT_FILENO, str, len))
		ft_exit(EXIT_FAILURE);
	(*increment)++;
}

void	push_swap_solve_internal_divide_print(
	t_push_swap_solve_internal_print_divide *param
)
{
	size_t		a;
	size_t		b;
	size_t		c;
	ptrdiff_t	offset;
	ptrdiff_t	direction;

	a = 0;
	b = 0;
	c = 0;
	offset = 0;
	if (param->reverse)
		offset = param->s.count_a + param->s.count_b + param->s.count_c;
	direction = 1;
	if (param->reverse)
		direction = -1;
	while (a + b + c != param->s.count_a + param->s.count_b + param->s.count_c)
	{
		if (param->s.all[offset] == param->s.part_a[a])
			internal(param->to_a, param->to_a_length, &a);
		else if (param->s.all[offset] == param->s.part_b[b])
			internal(param->to_b, param->to_b_length, &b);
		else
			internal(param->to_c, param->to_c_length, &c);
		offset += direction;
	}
}
