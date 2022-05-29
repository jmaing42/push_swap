/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_internal.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:20:33 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/29 16:33:41 by Juyeong Maing    ###   ########.fr       */
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

# define PUSH_SWAP_SOLVE_INTERNAL_TYPE_SORT_ONLY_LEFT_ASC 0
# define PUSH_SWAP_SOLVE_INTERNAL_TYPE_SORT_ONLY_RIGHT_ASC 1
# define PUSH_SWAP_SOLVE_INTERNAL_TYPE_SORT_AND_MOVE_LEFT_TO_RIGHT_ASC 2
# define PUSH_SWAP_SOLVE_INTERNAL_TYPE_SORT_AND_MOVE_RIGHT_TO_LEFT_ASC 3
# define PUSH_SWAP_SOLVE_INTERNAL_TYPE_SORT_ONLY_LEFT_DESC 4
# define PUSH_SWAP_SOLVE_INTERNAL_TYPE_SORT_ONLY_RIGHT_DESC 5
# define PUSH_SWAP_SOLVE_INTERNAL_TYPE_SORT_AND_MOVE_LEFT_TO_RIGHT_DESC 6
# define PUSH_SWAP_SOLVE_INTERNAL_TYPE_SORT_AND_MOVE_RIGHT_TO_LEFT_DESC 7

bool	push_swap_solve_internal_direction_is_reverse_order(
			int type);
bool	push_swap_solve_internal_direction_is_reverse_direction(
			int type);
int		push_swap_solve_internal_direction_inverse_order(
			int type);
int		push_swap_solve_internal_direction_inverse_direction(
			int type);

void	push_swap_solve_internal_operation_px(
			size_t a,
			size_t b,
			bool reverse_direction);
void	push_swap_solve_internal_operation_sx(
			bool right);
void	push_swap_solve_internal_operation_rx(
			size_t a,
			size_t b,
			bool reverse_direction);
void	push_swap_solve_internal_operation_rrx(
			size_t a,
			size_t b,
			bool reverse_direction);

void	push_swap_solve_internal_sort_only(
			t_push_swap *context,
			int *a,
			size_t count,
			int type);
void	push_swap_solve_internal_sort_and_move(
			t_push_swap *context,
			int *a,
			size_t count,
			int type);

#endif
