/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_divide_from_bottom.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:03:25 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/23 11:20:01 by Juyeong Maing    ###   ########.fr       */
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
		&& args->array[index]
		== args->p->array[args->p->length - 1 - *p]
	)
	{
		(*p)++;
		return (ps_solve_util_move_bst(args->stream, args->from_right));
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
		args->q->length > *q
		&& args->array[index]
		== args->q->array[args->q->length - 1 - *q]
	)
	{
		(*q)++;
		return (ps_solve_util_move_bot(args->stream, args->from_right));
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
		args->r->length > *r
		&& args->array[index]
		== args->r->array[args->r->length - 1 - *r]
	)
	{
		(*r)++;
		return (ps_solve_util_move_bob(args->stream, args->from_right));
	}
	return (false);
}

t_err	ps_solve_util_divide_from_bottom(
	const t_ps_solve_util_divide *params
)
{
	size_t			p_out;
	size_t			q_out;
	size_t			r_out;
	const size_t	length
		= params->p->length + params->q->length + params->r->length;

	p_out = 0;
	q_out = 0;
	r_out = 0;
	while (
		params->p->length != p_out
		|| params->q->length != q_out
		|| params->r->length != r_out
	)
	{
		if (
			process_p(params, &p_out, length - (p_out + q_out + r_out) - 1)
			|| process_q(params, &q_out, length - (p_out + q_out + r_out) - 1)
			|| process_r(params, &r_out, length - (p_out + q_out + r_out) - 1)
		)
			return (true);
	}
	return (false);
}
