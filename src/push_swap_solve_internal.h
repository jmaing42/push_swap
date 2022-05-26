/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_internal.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:20:33 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/27 01:58:01 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_SOLVE_INTERNAL_H
# define PUSH_SWAP_SOLVE_INTERNAL_H

# include "push_swap_solve.h"

typedef struct s_push_swap_solve_internal_collect
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
}	t_push_swap_solve_internal_collect;

typedef struct s_push_swap_internal_part
{
	size_t	count;
	int		start;
	int		end;
}	t_push_swap_internal_part;

typedef struct s_push_swap_sort_internal_divide
{
	int							*arr;
	t_push_swap_internal_part	self_bottom;
	t_push_swap_internal_part	other_top;
	t_push_swap_internal_part	other_bottom;
	bool						is_right;
	bool						is_desc;
}	t_push_swap_sort_internal_divide;

void	push_swap_sort_internal_sort(
			int *ptr,
			size_t length,
			bool reverse_order);
void	push_swap_solve_internal_collect(
			t_push_swap_solve_internal_collect collect);
void	push_swap_sort_internal_divide(
			t_push_swap_sort_internal_divide divide);

void	rx(size_t a, size_t b);
void	rrx(size_t a, size_t b);
void	sa(void);
void	sb(void);
void	px(size_t a, size_t b);

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

typedef enum e_push_swap_solve_internal_direction
{
	SORT_ONLY_LEFT_TO_RIGHT,
	SORT_ONLY_RIGHT_TO_LEFT,
	SORT_AND_MOVE_LEFT_TO_RIGHT,
	SORT_AND_MOVE_RIGHT_TO_LEFT,
}	t_push_swap_solve_internal_direction;

void	push_swap_solve_internal_sort_only(
			t_push_swap *context,
			int *a,
			size_t count,
			t_push_swap_solve_internal_direction direction);
void	push_swap_solve_internal_sort_and_move(
			t_push_swap *context,
			int *a,
			size_t count,
			t_push_swap_solve_internal_direction direction);

#endif
