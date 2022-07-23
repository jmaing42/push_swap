/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_move_t.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:15:22 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/23 12:21:56 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

#include <stdio.h>

t_err	ps_solve_util_move_tsb(
	t_ps_stream *stream,
	bool from_right
)
{
	(void)stream;
	if (from_right)
		puts("rb");
	else
		puts("ra");
	return (false);
}

t_err	ps_solve_util_move_tot(
	t_ps_stream *stream,
	bool from_right
)
{
	(void)stream;
	if (from_right)
		puts("pa");
	else
		puts("pb");
	return (false);
}

t_err	ps_solve_util_move_tob(
	t_ps_stream *stream,
	bool from_right
)
{
	(void)stream;
	if (from_right)
		puts("pa\nra");
	else
		puts("pb\nrb");
	return (false);
}
