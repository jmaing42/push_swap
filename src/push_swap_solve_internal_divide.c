/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_internal_divide.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:20:27 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/04 16:15:56 by Juyeong Maing    ###   ########.fr       */
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
	t_push_swap_solve_internal_print_divide *p
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
	if (p->reverse)
		offset = p->s.count_a + p->s.count_b + p->s.count_c;
	direction = 1;
	if (p->reverse)
		direction = -1;
	while (a + b + c != p->s.count_a + p->s.count_b + p->s.count_c)
	{
		if (p->s.all[offset] == p->s.part_a[a] && a != p->s.count_a)
			internal(p->to_a, p->to_a_length, &a);
		else if (p->s.all[offset] == p->s.part_b[b] && b != p->s.count_b)
			internal(p->to_b, p->to_b_length, &b);
		else
			internal(p->to_c, p->to_c_length, &c);
		offset += direction;
	}
}
