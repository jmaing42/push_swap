/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_do.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 23:58:02 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/14 00:12:40 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

#include "ft_cstring.h"

t_err	checker_do(t_checker_state *self, const char *operation)
{
	if (!ft_strcmp(operation, "pa\n"))
		checker_state_operation_pa(self);
	else if (!ft_strcmp(operation, "pb\n"))
		checker_state_operation_pb(self);
	else if (!ft_strcmp(operation, "sa\n"))
		checker_state_operation_sa(self);
	else if (!ft_strcmp(operation, "sb\n"))
		checker_state_operation_sb(self);
	else if (!ft_strcmp(operation, "ss\n"))
		checker_state_operation_ss(self);
	else if (!ft_strcmp(operation, "ra\n"))
		checker_state_operation_ra(self);
	else if (!ft_strcmp(operation, "rb\n"))
		checker_state_operation_rb(self);
	else if (!ft_strcmp(operation, "rr\n"))
		checker_state_operation_rr(self);
	else if (!ft_strcmp(operation, "rra\n"))
		checker_state_operation_rra(self);
	else if (!ft_strcmp(operation, "rrb\n"))
		checker_state_operation_rrb(self);
	else if (!ft_strcmp(operation, "rrr\n"))
		checker_state_operation_rrr(self);
	else
		return (true);
	return (false);
}
