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

#include "ft_types.h"
#include "c.h"

static t_ps_stream_internal_node	*new_node(void)
{
	t_ps_stream_internal_node *const	result
		= c_malloc(sizeof(t_ps_stream_internal_node));

	if (!result)
		return (NULL);
	result->pa = 0;
	result->pb = 0;
	result->a = NULL;
	result->ac = 0;
	result->b = NULL;
	result->bc = 0;
	return (result);
}

t_err	ps_stream_internal_append(t_ps_stream *self)
{
	t_ps_stream_internal_node *const	node = new_node();
	t_err								result;

	if (!node)
		return (true);
	result = self->vec->v->push(self->vec, &node);
	if (result)
		c_free(node);
	return (result);
}
