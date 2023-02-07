/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_collect_to_bottom.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:02:05 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 20:02:10 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

static t_err	process_p(
	const t_ps_solve_util_input *input,
	size_t *p,
	size_t q,
	size_t r
)
{
	if (
		input->p->length > *p
		&& (
			input->q->length == q
			|| input->q->array[q]
			> input->p->array[*p]
		)
		&& (
			input->r->length == r
			|| input->r->array[input->r->length - 1 - r]
			> input->p->array[*p]
		)
	)
	{
		(*p)++;
		return (ps_solve_util_move_tsb(input->stream, input->from_right));
	}
	return (false);
}

static t_err	process_q(
	const t_ps_solve_util_input *input,
	size_t p,
	size_t *q,
	size_t r
)
{
	if (
		input->q->length > *q
		&& (
			input->p->length == p
			|| input->p->array[p]
			> input->q->array[*q]
		)
		&& (
			input->r->length == r
			|| input->r->array[input->r->length - 1 - r]
			> input->q->array[*q]
		)
	)
	{
		(*q)++;
		return (ps_solve_util_move_tob(input->stream, !input->from_right));
	}
	return (false);
}

static t_err	process_r(
	const t_ps_solve_util_input *input,
	size_t p,
	size_t q,
	size_t *r
)
{
	if (
		input->r->length > *r
		&& (
			input->p->length == p
			|| input->p->array[p]
			> input->r->array[input->r->length - 1 - *r]
		)
		&& (
			input->q->length == q
			|| input->q->array[q]
			> input->r->array[input->r->length - 1 - *r]
		)
	)
	{
		(*r)++;
		return (ps_solve_util_move_bob(input->stream, !input->from_right));
	}
	return (false);
}

t_err	ps_solve_util_collect_to_bottom(
	const t_ps_solve_util_input input
)
{
	size_t	p_out;
	size_t	q_out;
	size_t	r_out;

	p_out = 0;
	q_out = 0;
	r_out = 0;
	while (
		input.p->length != p_out
		|| input.q->length != q_out
		|| input.r->length != r_out
	)
	{
		if (
			process_p(&input, &p_out, q_out, r_out)
			|| process_q(&input, p_out, &q_out, r_out)
			|| process_r(&input, p_out, q_out, &r_out)
		)
			return (true);
	}
	return (false);
}
