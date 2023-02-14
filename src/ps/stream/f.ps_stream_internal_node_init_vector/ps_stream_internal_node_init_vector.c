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

#include "ds_vector.h"
#include "util.h"

t_err	ps_stream_internal_node_init_vector(
	t_ds_vector **out
)
{
	if (*out)
		return (false);
	return (
		util_nonnull(
			ds_vector_new(sizeof(t_ps_stream_internal_command_node), NULL),
			(void **)out
		)
	);
}
