/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_state.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:28:33 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/11 21:49:56 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_STATE_H
# define CHECKER_STATE_H

# include <stddef.h>
# include <stdbool.h>

typedef struct t_checker_state_part
{
	int		*arr;
	size_t	capacity;
	size_t	offset;
	size_t	size;
}	t_checker_state_part;

typedef struct t_checker_state
{
	t_checker_state_part	a;
	t_checker_state_part	b;
}	t_checker_state;

void	checker_state_part_operation_push(t_checker_state_part *self, int n);
bool	checker_state_part_operation_pop(t_checker_state_part *self, int *out);
void	checker_state_part_operation_swap(t_checker_state_part *self);
void	checker_state_part_operation_rotate(t_checker_state_part *self);
void	checker_state_part_operation_reverse_rotate(t_checker_state_part *self);

void	checker_state_operation_pa(t_checker_state *self);
void	checker_state_operation_pb(t_checker_state *self);
void	checker_state_operation_sa(t_checker_state *self);
void	checker_state_operation_sb(t_checker_state *self);
void	checker_state_operation_ss(t_checker_state *self);
void	checker_state_operation_ra(t_checker_state *self);
void	checker_state_operation_rb(t_checker_state *self);
void	checker_state_operation_rr(t_checker_state *self);
void	checker_state_operation_rra(t_checker_state *self);
void	checker_state_operation_rrb(t_checker_state *self);
void	checker_state_operation_rrr(t_checker_state *self);

#endif
