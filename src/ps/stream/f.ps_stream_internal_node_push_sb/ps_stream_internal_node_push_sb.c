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

#include "ft_types.h"
#include "o_disposable.h"

t_err	ps_stream_internal_node_push_sb(
	t_ps_stream_internal_node *self,
	bool *out_remove
)
{
	if (ps_stream_internal_node_create_b(self))
		return (true);
	if (ps_stream_internal_node_vec_push_s(self->b, &self->bc))
		return (true);
	if (!self->bc)
		o_disposable_dispose_p((t_o_disposable **)&self->b);
	*out_remove = (!self->pa && !self->pb && !self->a && !self->b);
	return (false);
}
