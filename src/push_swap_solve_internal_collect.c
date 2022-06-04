/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_internal_collect.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:20:27 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/04 18:03:31 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solve_internal.h"

#include <stdlib.h>
#include <unistd.h>

#include "ft_io.h"
#include "ft_exit.h"

void	push_swap_solve_internal_collect(t_push_swap_solve_internal *p)
{
	size_t	a;
	size_t	b;
	size_t	c;
	size_t	i;

	a = 0;
	b = 0;
	c = 0;
	i = 0;
	while (i != p->count_a + p->count_b + p->count_c)
	{
		if (a < p->count_a
			&& (b == p->count_b || p->part_a[a] < p->part_b[b])
			&& (c == p->count_c || p->part_a[a] < p->part_c[c]))
			p->all[i++] = p->part_a[a++];
		else if (b < p->count_b
			&& (a == p->count_a || p->part_b[b] < p->part_a[a])
			&& (c == p->count_c || p->part_b[b] < p->part_c[c]))
			p->all[i++] = p->part_b[b++];
		else
			p->all[i++] = p->part_c[c++];
	}
}

static void	internal(const char *str, size_t len, size_t *increment)
{
	if (ft_write(STDOUT_FILENO, str, len))
		ft_exit(EXIT_FAILURE);
	(*increment)++;
}

static void	push_swap_solve_internal_collect_print_internal(
	t_push_swap_solve_internal_print_collect *p,
	size_t *a,
	size_t *b,
	size_t *c
)
{
	if (p->s.all[*a + *b + *c] == p->s.part_a[*a] && *a != p->s.count_a)
	{
		if (ft_write(STDOUT_FILENO, p->from_a, p->from_a_length))
			ft_exit(EXIT_FAILURE);
		(*a)++;
	}
	else if (p->s.all[*a + *b + *c] == p->s.part_b[*b] && *b != p->s.count_b)
	{
		if (ft_write(STDOUT_FILENO, p->from_b, p->from_b_length))
			ft_exit(EXIT_FAILURE);
		(*b)++;
	}
	else
	{
		if (ft_write(STDOUT_FILENO, p->from_c, p->from_c_length))
			ft_exit(EXIT_FAILURE);
		(*c)++;
	}
}

void	push_swap_solve_internal_collect_print(
	t_push_swap_solve_internal_print_collect *p
)
{
	size_t		a;
	size_t		b;
	size_t		c;

	if (p->reverse_a)
		push_swap_sort_internal_reverse(p->s.part_a, p->s.count_a);
	if (p->reverse_b)
		push_swap_sort_internal_reverse(p->s.part_b, p->s.count_b);
	if (p->reverse_c)
		push_swap_sort_internal_reverse(p->s.part_c, p->s.count_c);
	push_swap_solve_internal_collect(&p->s);
	a = 0;
	b = 0;
	c = 0;
	while (a + b + c != p->s.count_a + p->s.count_b + p->s.count_c)
		push_swap_solve_internal_collect_print_internal(p, &a, &b, &c);
	if (p->reverse_a)
		push_swap_sort_internal_reverse(p->s.part_a, p->s.count_a);
	if (p->reverse_b)
		push_swap_sort_internal_reverse(p->s.part_b, p->s.count_b);
	if (p->reverse_c)
		push_swap_sort_internal_reverse(p->s.part_c, p->s.count_c);
}
