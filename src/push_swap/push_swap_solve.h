/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:20:33 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/25 19:30:16 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_SOLVE_H
# define PUSH_SWAP_SOLVE_H

# include "push_swap.h"

void	push_swap_solve(
			t_push_swap *self,
			const int *arr,
			size_t count);
void	push_swap_solve_sort_only(
			t_push_swap *self,
			int *arr,
			size_t count,
			bool from_right);
void	push_swap_solve_sort_and_move(
			t_push_swap *self,
			int *arr,
			size_t count,
			bool from_right);

#endif
