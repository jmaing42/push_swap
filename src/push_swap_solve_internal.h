/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_internal.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:20:33 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/25 21:40:20 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_SOLVE_INTERNAL_H
# define PUSH_SWAP_SOLVE_INTERNAL_H

# include "push_swap_solve.h"

typedef struct s_push_swap_internal_collect
{
	int		*arr;
	size_t	self_bottom;
	size_t	self_bottom_offset;
	size_t	other_top;
	size_t	other_top_offset;
	size_t	other_bottom;
	size_t	other_bottom_offset;
	bool	is_right;
	bool	is_desc;
}	t_push_swap_internal_collect;

typedef struct s_push_swap_internal_part
{
	size_t	count;
	int		start;
	int		end;
}	t_push_swap_internal_part;

typedef struct s_push_swap_internal_divide
{
	int							*arr;
	t_push_swap_internal_part	self_bottom;
	t_push_swap_internal_part	other_top;
	t_push_swap_internal_part	other_bottom;
	bool						is_right;
	bool						is_desc;
}	t_push_swap_internal_divide;

void	push_swap_internal_sort(
			int *ptr,
			size_t length,
			bool reverse_order);
void	push_swap_internal_collect(
			t_push_swap_internal_collect collect);
void	push_swap_internal_divide(
			t_push_swap_internal_divide divide);

void	rx(size_t a, size_t b);
void	rrx(size_t a, size_t b);
void	sa(void);
void	sb(void);
void	pa(size_t count);
void	pb(size_t count);

void	push_swap_solve_internal_ltl(
			t_push_swap *self,
			size_t offset,
			size_t count,
			bool reverse_order);
void	push_swap_solve_internal_ltr(
			t_push_swap *self,
			size_t offset,
			size_t count,
			bool reverse_order);
void	push_swap_solve_internal_rtl(
			t_push_swap *self,
			size_t offset,
			size_t count,
			bool reverse_order);
void	push_swap_solve_internal_rtr(
			t_push_swap *self,
			size_t offset,
			size_t count,
			bool reverse_order);

#endif
