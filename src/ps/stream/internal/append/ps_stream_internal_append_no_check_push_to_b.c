/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_append_no_check_push_to_b.c     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:44:48 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/14 23:52:03 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

void	ps_stream_internal_append_no_check_push_to_b(
	t_ps_stream *self,
	size_t count
)
{
	self->tail->value.separator->pb += count;
	self->a -= count;
	self->b += count;
}
