/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_clear_node_parallel.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:01:48 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/15 00:56:16 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

#include <stdlib.h>

#include "ft_size_t.h"

bool	ps_stream_internal_clear_node_parallel(
	t_ps_stream_node_parallel *self
)
{
	ps_stream_internal_clear_parallel(&self->a);
	ps_stream_internal_clear_parallel(&self->b);
	if (self->a.head || self->b.head)
		return (false);
	free(self);
	return (true);
}
