/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_file_name (file name is useless too)          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42header-remover <whatever@example.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by file history     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

#include <stdbool.h>

#include "ds_vector.h"
#include "ps.h"

static const t_ps_command	g_command[4][3] = {
{PS_NOP, PS_NOP, PS_NOP},
{PS_SA, PS_RA, PS_RRA},
{PS_SB, PS_RB, PS_RRB},
{PS_SS, PS_RR, PS_RRR},
};

typedef struct s_locals
{
	size_t	y;
	size_t	x;
	bool	next_x;
	bool	next_y;
}	t_locals;

static t_err	add(
	t_ds_vector *mut_result,
	t_ps_stream_internal_score_matrix_pack pack,
	t_locals l
)
{
	t_ps_stream_internal_command	type;

	if (l.next_x)
		type = pack.b[l.x];
	else
		type = pack.a[l.y];
	return (
		ps_stream_internal_push(
			mut_result,
			g_command[(!!l.next_y) + 2 * (!!l.next_x)][type]
	));
}

static void	move(
	t_ps_stream_internal_score_matrix_pack pack,
	t_locals *l
)
{
	if (!l->x)
	{
		l->next_y = true;
		l->next_x = false;
	}
	else if (pack.matrix[l->y][l->x - 1] == pack.matrix[l->y][l->x])
	{
		l->next_y = false;
		l->next_x = true;
	}
	else if (!l->y)
	{
		l->next_y = false;
		l->next_x = true;
	}
	else if (pack.matrix[l->y - 1][l->x] == pack.matrix[l->y][l->x])
	{
		l->next_y = true;
		l->next_x = false;
	}
	else
	{
		l->next_y = true;
		l->next_x = true;
	}
}

static t_err	fill(
	t_ds_vector *mut_result,
	t_ps_stream_internal_score_matrix_pack pack
)
{
	t_locals	l;

	l.y = pack.height - 1;
	l.x = pack.width - 1;
	while (l.y != 0 || l.x != 0)
	{
		move(pack, &l);
		if (add(mut_result, pack, l))
			return (true);
		if (l.next_y)
			l.y--;
		if (l.next_x)
			l.x--;
	}
	return (false);
}

t_err	ps_stream_internal_s_r_rr(
	t_ps_stream_internal_node *node,
	t_ds_vector **out
)
{
	t_ds_vector *const						result
		= ds_vector_new(sizeof(t_ps_command), NULL);
	t_ps_stream_internal_score_matrix_pack	pack;

	if (!result)
		return (NULL);
	if (ps_stream_internal_build_score_matrix_pack(node, &pack))
	{
		o_disposable_dispose((t_o_disposable *)result);
		return (true);
	}
	if (fill(result, pack))
	{
		o_disposable_dispose((t_o_disposable *)result);
		ps_stream_internal_free_score_matrix_pack(pack);
		return (true);
	}
	ps_stream_internal_free_score_matrix_pack(pack);
	*out = result;
	return (false);
}
