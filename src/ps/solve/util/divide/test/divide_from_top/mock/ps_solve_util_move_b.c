/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_move_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:15:22 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/23 12:24:23 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include <stdio.h>

t_err	ps_solve_util_move_bst(
	t_ps_stream *stream,
	bool from_right
)
{
	(void)stream;
	if (from_right)
		puts("rrb");
	else
		puts("rra");
	return (false);
}

t_err	ps_solve_util_move_bot(
	t_ps_stream *stream,
	bool from_right
)
{
	(void)stream;
	if (from_right)
		puts("rrb\npa");
	else
		puts("rra\npb");
	return (false);
}

t_err	ps_solve_util_move_bob(
	t_ps_stream *stream,
	bool from_right
)
{
	(void)stream;
	if (from_right)
		puts("rrb\npa\nra");
	else
		puts("rra\npb\nrb");
	return (false);
}
