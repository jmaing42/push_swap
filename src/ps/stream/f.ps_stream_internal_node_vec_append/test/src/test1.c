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

#include "test.h"

#include <stddef.h>
#include <assert.h>

#include "ps_stream_internal.h"
#include "ds_vector.h"

typedef t_err		(*t_f)(
	t_ds_vector *self,
	t_ps_stream_internal_command command
);

static const t_f	g_testee1 = &ps_stream_internal_node_vec_append;

void	test1(void)
{
	t_ds_vector							*vec;
	t_ps_stream_internal_command_node	node;

	vec = NULL;
	assert(!ps_stream_internal_node_init_vector(&vec));
	assert(vec->v->length(vec) == 0);
	assert(!g_testee1(vec, PS_STREAM_INTERNAL_COMMAND_S));
	assert(vec->v->length(vec) == 1);
	assert(!g_testee1(vec, PS_STREAM_INTERNAL_COMMAND_S));
	assert(vec->v->length(vec) == 1);
	assert(vec->v->get(vec, 0, &node));
	assert(node.command == PS_STREAM_INTERNAL_COMMAND_S);
	assert(node.count == 2);
	assert(!g_testee1(vec, PS_STREAM_INTERNAL_COMMAND_R));
	assert(vec->v->length(vec) == 2);
	assert(!g_testee1(vec, PS_STREAM_INTERNAL_COMMAND_RR));
	assert(vec->v->length(vec) == 3);
	assert(!g_testee1(vec, PS_STREAM_INTERNAL_COMMAND_RR));
	assert(vec->v->length(vec) == 3);
	assert(vec->v->get(vec, 2, &node));
	assert(node.command == PS_STREAM_INTERNAL_COMMAND_RR);
	assert(node.count == 2);
	assert(!g_testee1(vec, PS_STREAM_INTERNAL_COMMAND_S));
	assert(vec->v->length(vec) == 4);
}
