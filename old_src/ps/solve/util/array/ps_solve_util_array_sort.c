/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_array_sort.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:20:31 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 08:30:53 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

void	ps_solve_util_array_sort(
	t_ps_solve_util_array_mutable *self
)
{
	ps_solve_util_sort(self->array, self->length);
}
