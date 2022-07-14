/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_append_no_check_push_to_b.c     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:44:48 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/14 23:44:49 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

#include "ft_size_t.h"

void	ps_stream_internal_append_no_check_push_to_a(
	t_ps_stream *self,
	size_t count
)
{
	count = ft_size_t_min(count, self->a);
	self->tail->value.separator->pb += count;
	self->a -= count;
	self->b += count;
}
