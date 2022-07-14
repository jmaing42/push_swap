/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_clear_node_separator.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:01:48 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/15 00:33:29 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

#include <stdlib.h>

#include "ft_size_t.h"

bool	ps_stream_internal_clear_node_separator(
	t_ps_stream_node_separator *self
)
{
	const size_t	common = ft_size_t_min(self->pa, self->pb);

	self->pa -= common;
	self->pb -= common;
	if (self->pa || self->pb)
		return (false);
	free(self);
	return (true);
}
