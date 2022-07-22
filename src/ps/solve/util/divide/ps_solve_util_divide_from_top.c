/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_divide_from_top.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:03:25 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/23 00:40:04 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

static t_err	process_p(
	const t_ps_solve_util_divide *args,
	size_t *p,
	size_t index
)
{
	if (
		args->p->length > *p
		&& args->array[index] == args->p->array[*p]
	)
	{
		(*p)++;
		return (ps_solve_util_move_tsb(args->stream, args->from_right));
	}
	return (false);
}

static t_err	process_q(
	const t_ps_solve_util_divide *args,
	size_t *q,
	size_t index
)
{
	if (
		args->p->length > *q
		&& args->array[index] == args->q->array[*q]
	)
	{
		(*q)++;
		return (ps_solve_util_move_tot(args->stream, args->from_right));
	}
	return (false);
}

static t_err	process_r(
	const t_ps_solve_util_divide *args,
	size_t *r,
	size_t index
)
{
	if (
		args->p->length > *r
		&& args->array[index] == args->r->array[*r]
	)
	{
		(*r)++;
		return (ps_solve_util_move_tob(args->stream, args->from_right));
	}
	return (false);
}

t_err	ps_solve_util_divide_from_top(
	const t_ps_solve_util_divide params
)
{
	size_t	p_out;
	size_t	q_out;
	size_t	r_out;

	p_out = 0;
	q_out = 0;
	r_out = 0;
	while (
		params.p->length != p_out
		|| params.q->length != q_out
		|| params.r->length != r_out
	)
	{
		if (process_p(&params, &p_out, p_out + q_out + r_out))
			return (true);
		if (process_q(&params, &q_out, p_out + q_out + r_out))
			return (true);
		if (process_r(&params, &r_out, p_out + q_out + r_out))
			return (true);
	}
	return (false);
}
