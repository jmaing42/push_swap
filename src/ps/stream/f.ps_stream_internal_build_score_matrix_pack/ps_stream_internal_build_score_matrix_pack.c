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

#include <stddef.h>

#include "c.h"
#include "ds_vector.h"

static size_t	**allocate_score_matrix(size_t height, size_t width)
{
	size_t **const	result = c_malloc(sizeof(size_t *) * height);
	size_t			i;

	if (!result)
		return (NULL);
	i = -1;
	while (++i < height)
	{
		result[i] = c_malloc(sizeof(size_t) * width);
		if (!result[i])
		{
			ps_stream_internal_free_score_matrix(result, i);
			return (NULL);
		}
	}
	return (result);
}

static t_ps_stream_internal_command	*flat(
	t_ds_vector *vec,
	size_t precalculated_length
)
{
	t_ps_stream_internal_command *const	result
		= c_malloc(sizeof(t_ps_stream_internal_command) * precalculated_length);
	t_ps_stream_internal_command_node	tmp;
	size_t								i;
	size_t								j;
	size_t								k;

	if (!result)
		return (NULL);
	i = 0;
	j = -1;
	while (++j < vec->v->length(vec))
	{
		vec->v->get(vec, j, &tmp);
		k = -1;
		while (++k < tmp.count)
			result[i++] = tmp.command;
	}
	return (result);
}

static size_t	score(
	const t_ps_stream_internal_score_matrix_pack *pack,
	size_t y,
	size_t x
)
{
	const t_ps_stream_internal_command	a = pack->a[y];
	const t_ps_stream_internal_command	b = pack->b[x];
	size_t								result;
	size_t								tmp;

	result = pack->matrix[y + 1][x];
	tmp = pack->matrix[y][x + 1];
	if (tmp > result)
		result = tmp;
	if (a == b)
	{
		tmp = pack->matrix[y][x] + 1;
		if (tmp > result)
			result = tmp;
	}
	return (result);
}

static void	fill(const t_ps_stream_internal_score_matrix_pack *pack)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < pack->width)
		pack->matrix[0][i] = 0;
	i = 0;
	while (++i < pack->height)
		pack->matrix[i][0] = 0;
	i = -1;
	while (++i < pack->ac)
	{
		j = -1;
		while (++j < pack->bc)
			pack->matrix[i + 1][j + 1] = score(pack, i, j);
	}
}

t_err	ps_stream_internal_build_score_matrix_pack(
	t_ps_stream_internal_node *node,
	t_ps_stream_internal_score_matrix_pack *out
)
{
	const t_ps_stream_internal_score_matrix_pack	result = {
		allocate_score_matrix(node->ac + 1, node->bc + 1),
		node->ac + 1,
		node->bc + 1,
		flat(node->a, node->ac),
		node->ac,
		flat(node->b, node->bc),
		node->bc,
	};

	if (!result.matrix || !result.a || !result.b)
	{
		c_free(result.a);
		c_free(result.b);
		if (result.matrix)
			ps_stream_internal_free_score_matrix(result.matrix, result.height);
		return (true);
	}
	fill(&result);
	*out = result;
	return (false);
}
