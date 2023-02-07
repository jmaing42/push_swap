/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_divide_from_top.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:03:25 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 08:45:54 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

static t_err	process_p(
	const t_ps_solve_util_input *input,
	size_t *p,
	size_t index
)
{
	if (
		input->p->length > *p
		&& input->array[index] == input->p->array[*p]
	)
	{
		(*p)++;
		return (ps_solve_util_move_tsb(input->stream, input->from_right));
	}
	return (false);
}

static t_err	process_q(
	const t_ps_solve_util_input *input,
	size_t *q,
	size_t index
)
{
	if (
		input->p->length > *q
		&& input->array[index] == input->q->array[*q]
	)
	{
		(*q)++;
		return (ps_solve_util_move_tot(input->stream, input->from_right));
	}
	return (false);
}

static t_err	process_r(
	const t_ps_solve_util_input *input,
	size_t *r,
	size_t index
)
{
	if (
		input->p->length > *r
		&& input->array[index] == input->r->array[*r]
	)
	{
		(*r)++;
		return (ps_solve_util_move_tob(input->stream, input->from_right));
	}
	return (false);
}

t_err	ps_solve_util_divide_from_top(
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
			process_p(&input, &p_out, p_out + q_out + r_out)
			|| process_q(&input, &q_out, p_out + q_out + r_out)
			|| process_r(&input, &r_out, p_out + q_out + r_out)
		)
			return (true);
	}
	return (false);
}
