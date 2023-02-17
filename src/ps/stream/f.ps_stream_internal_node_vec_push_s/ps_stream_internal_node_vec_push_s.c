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

t_err	ps_stream_internal_node_vec_push_s(
	t_ds_vector *self,
	size_t *mut_count
)
{
	if (ps_stream_internal_node_vec_remove(self, PS_STREAM_INTERNAL_COMMAND_S))
	{
		(*mut_count)--;
		return (false);
	}
	if (ps_stream_internal_node_vec_append(self, PS_STREAM_INTERNAL_COMMAND_S))
		return (true);
	(*mut_count)++;
	return (false);
}
