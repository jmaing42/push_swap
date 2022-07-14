/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_clear_last_node.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:45:32 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/14 23:45:36 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

bool	ps_stream_internal_clear_last_node(t_ps_stream_node *self)
{
	if (*self->value.type == PS_STREAM_NODE_TYPE_SEPARATOR)
		return (
			ps_stream_internal_clear_last_node_separator(self->value.separator)
		);
	else
		return (
			ps_stream_internal_clear_last_node_parallel(self->value.parallel)
		);
}
