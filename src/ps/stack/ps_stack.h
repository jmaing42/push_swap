/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:28:33 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/11 22:29:26 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STACK_H
# define PS_STACK_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_ps_stack_part
{
	int		*arr;
	size_t	capacity;
	size_t	offset;
	size_t	size;
}	t_ps_stack_part;

typedef struct s_ps_stack
{
	t_ps_stack_part	a;
	t_ps_stack_part	b;
}	t_ps_stack;

void	ps_stack_part_operation_push(t_ps_stack_part *self, int n);
bool	ps_stack_part_operation_pop(t_ps_stack_part *self, int *out);
void	ps_stack_part_operation_swap(t_ps_stack_part *self);
void	ps_stack_part_operation_rotate(t_ps_stack_part *self);
void	ps_stack_part_operation_reverse_rotate(t_ps_stack_part *self);

void	ps_stack_operation_pa(t_ps_stack *self);
void	ps_stack_operation_pb(t_ps_stack *self);
void	ps_stack_operation_sa(t_ps_stack *self);
void	ps_stack_operation_sb(t_ps_stack *self);
void	ps_stack_operation_ss(t_ps_stack *self);
void	ps_stack_operation_ra(t_ps_stack *self);
void	ps_stack_operation_rb(t_ps_stack *self);
void	ps_stack_operation_rr(t_ps_stack *self);
void	ps_stack_operation_rra(t_ps_stack *self);
void	ps_stack_operation_rrb(t_ps_stack *self);
void	ps_stack_operation_rrr(t_ps_stack *self);

#endif
