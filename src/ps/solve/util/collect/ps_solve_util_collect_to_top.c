/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_collect_to_top.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:52:10 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/23 11:18:05 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

static t_err	process_p(
	const t_ps_solve_util_collect *args,
	size_t *p,
	size_t q,
	size_t r
)
{
	if (
		args->p->length > *p
		&& (
			args->q->length == q
			|| args->q->array[q]
			< args->p->array[args->p->length - 1 - *p]
		)
		&& (
			args->r->length == r
			|| args->r->array[args->r->length - 1 - r]
			< args->p->array[args->p->length - 1 - *p]
		)
	)
	{
		(*p)++;
		return (ps_solve_util_move_bst(args->stream, args->from_right));
	}
	return (false);
}

static t_err	process_q(
	const t_ps_solve_util_collect *args,
	size_t p,
	size_t *q,
	size_t r
)
{
	if (
		args->q->length > *q
		&& (
			args->p->length == p
			|| args->p->array[args->p->length - 1 - p]
			< args->q->array[*q]
		)
		&& (
			args->r->length == r
			|| args->r->array[args->r->length - 1 - r]
			< args->q->array[*q]
		)
	)
	{
		(*q)++;
		return (ps_solve_util_move_tot(args->stream, !args->from_right));
	}
	return (false);
}

static t_err	process_r(
	const t_ps_solve_util_collect *args,
	size_t p,
	size_t q,
	size_t *r
)
{
	if (
		args->r->length > *r
		&& (
			args->p->length == p
			|| args->p->array[args->p->length - 1 - p]
			< args->r->array[args->r->length - 1 - *r]
		)
		&& (
			args->q->length == q
			|| args->q->array[q]
			< args->r->array[args->r->length - 1 - *r]
		)
	)
	{
		(*r)++;
		return (ps_solve_util_move_bot(args->stream, !args->from_right));
	}
	return (false);
}

t_err	ps_solve_util_collect_to_top(
	const t_ps_solve_util_collect *params
)
{
	size_t	p_out;
	size_t	q_out;
	size_t	r_out;

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
			process_p(params, &p_out, q_out, r_out)
			|| process_q(params, p_out, &q_out, r_out)
			|| process_r(params, p_out, q_out, &r_out)
		)
			return (true);
	}
	return (false);
}
