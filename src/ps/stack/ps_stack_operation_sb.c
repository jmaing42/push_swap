/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_operation_sb.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:29:37 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/30 00:13:37 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

void	ps_stack_operation_sb(t_ps_stack *self)
{
	ps_stack_part_operation_swap(&self->b);
}
