/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_internal.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:20:33 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/04 18:37:25 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_SOLVE_INTERNAL_H
# define PUSH_SWAP_SOLVE_INTERNAL_H

# include "push_swap_solve.h"

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

bool	push_swap_solve_internal_type_is_reverse_order(
			int type);
bool	push_swap_solve_internal_type_is_reverse_direction(
			int type);
int		push_swap_solve_internal_type_inverse_order(
			int type);
int		push_swap_solve_internal_type_inverse_direction(
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

void	push_swap_solve_internal_sort(
			int *ptr,
			size_t length,
			bool reverse_order);
void	push_swap_sort_internal_reverse(
			int *ptr,
			size_t length);

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

typedef struct s_push_swap_solve_internal
{
	int		*all;
	int		*all_sorted;
	int		*part_a;
	int		*part_b;
	int		*part_c;
	size_t	c_a;
	size_t	c_b;
	size_t	c_c;
}	t_push_swap_solve_internal;

typedef struct s_push_swap_solve_internal_print_divide
{
	t_push_swap_solve_internal	s;
	const char					*to_a;
	const char					*to_b;
	const char					*to_c;
	size_t						to_a_length;
	size_t						to_b_length;
	size_t						to_c_length;
	bool						reverse;
}	t_push_swap_solve_internal_print_divide;

typedef struct s_push_swap_solve_internal_print_collect
{
	t_push_swap_solve_internal	s;
	const char					*from_a;
	const char					*from_b;
	const char					*from_c;
	size_t						from_a_length;
	size_t						from_b_length;
	size_t						from_c_length;
	bool						reverse_a;
	bool						reverse_b;
	bool						reverse_c;
}	t_push_swap_solve_internal_print_collect;

void	push_swap_solve_internal_divide(
			t_push_swap_solve_internal *param);
void	push_swap_solve_internal_collect(
			t_push_swap_solve_internal *param);
void	push_swap_solve_internal_divide_print(
			t_push_swap_solve_internal_print_divide *param);
void	push_swap_solve_internal_collect_print(
			t_push_swap_solve_internal_print_collect *param);

#endif
