/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_internal.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:20:33 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/04 10:46:18 by Juyeong Maing    ###   ########.fr       */
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
	int		*input;
	int		*a;
	int		*b;
	int		*c;
	size_t	count_a;
	size_t	count_b;
	size_t	count_c;
	bool	reverse_order;
}	t_push_swap_solve_internal;

void	push_swap_solve_internal_divide(t_push_swap_solve_internal *param);
void	push_swap_solve_internal_collect(t_push_swap_solve_internal *param);

#endif
