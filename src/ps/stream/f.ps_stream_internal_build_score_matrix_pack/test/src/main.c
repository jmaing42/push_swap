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

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>

#include "ft_types.h"
#include "ds_vector.h"

static t_err	push(t_ps_stream_internal_node *node, const char *command)
{
	if (!strcmp("sa", command))
		return (ps_stream_internal_node_vec_push_s(node->a, &node->ac));
	if (!strcmp("ra", command))
		return (ps_stream_internal_node_vec_push_r(node->a, &node->ac));
	if (!strcmp("rra", command))
		return (ps_stream_internal_node_vec_push_rr(node->a, &node->ac));
	if (!strcmp("sb", command))
		return (ps_stream_internal_node_vec_push_s(node->b, &node->bc));
	if (!strcmp("rb", command))
		return (ps_stream_internal_node_vec_push_r(node->b, &node->bc));
	if (!strcmp("rrb", command))
		return (ps_stream_internal_node_vec_push_rr(node->b, &node->bc));
	return (true);
}

static void	print(t_ps_stream_internal_score_matrix_pack pack)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < pack.height)
	{
		j = -1;
		while (++j < pack.width)
			assert(printf(" %zu", pack.matrix[i][j]) > 0);
		assert(printf("\n") > 0);
	}
}

static const size_t	g_size = sizeof(t_ps_stream_internal_command_node);

int	main(void)
{
	char									buffer[3];
	t_ps_stream_internal_node				node;
	t_ps_stream_internal_score_matrix_pack	pack;

	assert(node.a = ds_vector_new(g_size, NULL));
	assert(node.b = ds_vector_new(g_size, NULL));
	node.ac = 0;
	node.bc = 0;
	while (!feof(stdin) && !ferror(stdin))
		assert(
			(
				(scanf("%3s", buffer) == 1 && !push(&node, buffer))
				|| feof(stdin))
			&& !ferror(stdin));
	assert(!ps_stream_internal_build_score_matrix_pack(&node, &pack));
	print(pack);
}
