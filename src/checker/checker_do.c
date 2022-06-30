/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_do.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 23:58:02 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/30 00:14:27 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

#include "ft_cstring.h"

t_err	checker_do(t_ps_stack *self, const char *operation)
{
	if (!ft_strcmp(operation, "pa\n"))
		ps_stack_operation_pa(self);
	else if (!ft_strcmp(operation, "pb\n"))
		ps_stack_operation_pb(self);
	else if (!ft_strcmp(operation, "sa\n"))
		ps_stack_operation_sa(self);
	else if (!ft_strcmp(operation, "sb\n"))
		ps_stack_operation_sb(self);
	else if (!ft_strcmp(operation, "ss\n"))
		ps_stack_operation_ss(self);
	else if (!ft_strcmp(operation, "ra\n"))
		ps_stack_operation_ra(self);
	else if (!ft_strcmp(operation, "rb\n"))
		ps_stack_operation_rb(self);
	else if (!ft_strcmp(operation, "rr\n"))
		ps_stack_operation_rr(self);
	else if (!ft_strcmp(operation, "rra\n"))
		ps_stack_operation_rra(self);
	else if (!ft_strcmp(operation, "rrb\n"))
		ps_stack_operation_rrb(self);
	else if (!ft_strcmp(operation, "rrr\n"))
		ps_stack_operation_rrr(self);
	else
		return (true);
	return (false);
}
