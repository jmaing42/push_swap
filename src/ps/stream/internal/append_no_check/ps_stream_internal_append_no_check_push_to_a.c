/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_append_no_check_push_to_a.c     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:44:43 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/14 23:44:45 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

#include "ft_size_t.h"

void	ps_stream_internal_append_no_check_push_to_a(
	t_ps_stream *self,
	size_t count
)
{
	count = ft_size_t_min(count, self->b);
	self->tail->value.separator->pa += count;
	self->b -= count;
	self->a += count;
}
