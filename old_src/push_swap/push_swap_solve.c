/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:54:55 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/01 09:00:36 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream.h"
#include "push_swap.h"

#include "ps_solve.h"

t_err	push_swap_solve(const int *array, size_t length)
{
	t_ps_stream *const			stream = new_ps_stream(length, 0);
	const t_ps_solve_context	context = {
		stream,
		push_swap_get_table(),
		push_swap_get_table_size(),
	};
	bool						result;

	result = (
			!stream
			|| ps_solve_sxs(&context, array, length, false)
			);
	if (stream)
		ps_stream_free(stream);
	return (result);
}
