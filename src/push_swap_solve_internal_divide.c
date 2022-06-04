/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_internal_divide.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:20:27 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/04 19:55:48 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solve_internal.h"

#include <stdlib.h>
#include <unistd.h>

#include "ft_io.h"
#include "ft_exit.h"

void	push_swap_solve_internal_divide(t_push_swap_solve_internal *p)
{
	size_t			a;
	size_t			b;
	size_t			c;

	a = 0;
	b = 0;
	c = 0;
	while (a + b + c != p->c_a + p->c_b + p->c_c)
	{
		if ((!p->c_b && !p->c_c) || p->all[a + b + c] < (p->all_sorted[p->c_a]))
			p->part_a[a] = p->all[a + b + c];
		if ((!p->c_b && !p->c_c) || p->all[a + b + c] < (p->all_sorted[p->c_a]))
			a++;
		else if (!p->c_c || p->all[a + b + c] < p->all_sorted[p->c_a + p->c_b])
		{
			p->part_b[b] = p->all[a + b + c];
			b++;
		}
		else
		{
			p->part_c[c] = p->all[a + b + c];
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

static void	push_swap_solve_internal_divide_print_internal(
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
		offset = p->s.c_a + p->s.c_b + p->s.c_c;
	direction = 1;
	if (p->reverse)
		direction = -1;
	while (a + b + c != p->s.c_a + p->s.c_b + p->s.c_c)
	{
		if (a != p->s.c_a && p->s.all[offset] == p->s.part_a[a])
			internal(p->to_a, p->to_a_length, &a);
		else if (b != p->s.c_b && p->s.all[offset] == p->s.part_b[b])
			internal(p->to_b, p->to_b_length, &b);
		else
			internal(p->to_c, p->to_c_length, &c);
		offset += direction;
	}
}

void	push_swap_solve_internal_divide_print(
	t_push_swap_solve_internal_print_divide *p
)
{
	push_swap_solve_internal_divide(&p->s);
	push_swap_solve_internal_divide_print_internal(p);
}
