/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_state_operation_pb.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:29:37 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/11 21:57:23 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_state.h"

void	checker_state_operation_pb(t_checker_state *self)
{
	int	tmp;

	if (checker_state_part_operation_pop(&self->a, &tmp))
		checker_state_part_operation_push(&self->b, tmp);
}
