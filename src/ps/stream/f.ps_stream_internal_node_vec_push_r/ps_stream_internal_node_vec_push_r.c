/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_node_vec_push_r.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 00:55:17 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/02/18 00:59:26 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

#include "ft_types.h"

t_err	ps_stream_internal_node_vec_push_r(
	t_ds_vector *self,
	size_t *mut_count
)
{
	if (ps_stream_internal_node_vec_remove(self, PS_STREAM_INTERNAL_COMMAND_RR))
	{
		(*mut_count)--;
		return (false);
	}
	if (ps_stream_internal_node_vec_append(self, PS_STREAM_INTERNAL_COMMAND_R))
		return (true);
	(*mut_count)++;
	return (false);
}
