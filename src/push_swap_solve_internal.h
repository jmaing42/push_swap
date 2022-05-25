/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_internal.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:20:33 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/25 13:49:28 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_SOLVE_INTERNAL_H
# define PUSH_SWAP_SOLVE_INTERNAL_H

# include "push_swap_solve.h"

typedef struct s_push_swap_internal
{
	int		*arr;
	size_t	x_count;
	size_t	y_count;
	size_t	z_count;
	bool	is_right;
}	t_push_swap_internal;

void					push_swap_internal_sort(int *ptr, size_t length);
void					push_swap_internal_merge(t_push_swap_internal merge);
void					push_swap_internal_divide(t_push_swap_internal divide);
void					rx(size_t a, size_t b);
void					rrx(size_t a, size_t b);

void					push_swap_solve_internal_ltl(
							t_push_swap *self,
							size_t offset,
							size_t count,
							bool reverse_order);
void					push_swap_solve_internal_ltr(
							t_push_swap *self,
							size_t offset,
							size_t count,
							bool reverse_order);
void					push_swap_solve_internal_rtl(
							t_push_swap *self,
							size_t offset,
							size_t count,
							bool reverse_order);
void					push_swap_solve_internal_rtr(
							t_push_swap *self,
							size_t offset,
							size_t count,
							bool reverse_order);

#endif
