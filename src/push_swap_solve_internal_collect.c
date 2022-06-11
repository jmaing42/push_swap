/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_internal_collect.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:20:27 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/11 21:56:41 by Juyeong Maing    ###   ########.fr       */
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
	while (i != p->c_a + p->c_b + p->c_c)
	{
		if (a < p->c_a
			&& (b == p->c_b || p->part_a[a] < p->part_b[b])
			&& (c == p->c_c || p->part_a[a] < p->part_c[c]))
			p->all[i++] = p->part_a[a++];
		else if (b < p->c_b
			&& (a == p->c_a || p->part_b[b] < p->part_a[a])
			&& (c == p->c_c || p->part_b[b] < p->part_c[c]))
			p->all[i++] = p->part_b[b++];
		else
			p->all[i++] = p->part_c[c++];
	}
}

static void	push_swap_solve_internal_collect_print_internal(
	t_push_swap_solve_internal_print_collect *p,
	size_t *a,
	size_t *b,
	size_t *c
)
{
	if (p->s.all[*a + *b + *c] == p->s.part_a[*a] && *a != p->s.c_a)
	{
		if (ft_write(STDOUT_FILENO, p->from_a, p->from_a_length))
			ft_exit(EXIT_FAILURE);
		(*a)++;
	}
	else if (p->s.all[*a + *b + *c] == p->s.part_b[*b] && *b != p->s.c_b)
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
		push_swap_sort_internal_reverse(p->s.part_a, p->s.c_a);
	if (p->reverse_b)
		push_swap_sort_internal_reverse(p->s.part_b, p->s.c_b);
	if (p->reverse_c)
		push_swap_sort_internal_reverse(p->s.part_c, p->s.c_c);
	push_swap_solve_internal_collect(&p->s);
	a = 0;
	b = 0;
	c = 0;
	while (a + b + c != p->s.c_a + p->s.c_b + p->s.c_c)
		push_swap_solve_internal_collect_print_internal(p, &a, &b, &c);
	if (p->reverse_a)
		push_swap_sort_internal_reverse(p->s.part_a, p->s.c_a);
	if (p->reverse_b)
		push_swap_sort_internal_reverse(p->s.part_b, p->s.c_b);
	if (p->reverse_c)
		push_swap_sort_internal_reverse(p->s.part_c, p->s.c_c);
}
