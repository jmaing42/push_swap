/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve_internal_type.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 12:51:47 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/04 12:51:47 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solve_internal.h"

bool	push_swap_solve_internal_type_is_reverse_order(
	int type
)
{
	return (!!(type & 4));
}

bool	push_swap_solve_internal_type_is_reverse_direction(
	int type
)
{
	return (!!(type & 1));
}

int	push_swap_solve_internal_type_inverse_order(
	int type
)
{
	return (type ^ 4);
}

int	push_swap_solve_internal_type_inverse_direction(
	int type
)
{
	return (type ^ 1);
}
