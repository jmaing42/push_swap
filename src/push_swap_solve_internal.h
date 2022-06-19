/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_internal.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:20:33 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/19 20:37:46 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_SOLVE_INTERNAL_H
# define PUSH_SWAP_SOLVE_INTERNAL_H

# include "push_swap_solve.h"

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
			size_t length);
void	push_swap_solve_internal_reverse(
			int *ptr,
			size_t length);
void	push_swap_solve_internal_inverse(
			int *ptr,
			size_t length);

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

void	push_swap_solve_internal_sort_only(
			t_push_swap *context,
			int *arr,
			size_t count,
			bool from_right);
void	push_swap_solve_internal_sort_and_move(
			t_push_swap *context,
			int *arr,
			size_t count,
			bool from_right);

#endif
