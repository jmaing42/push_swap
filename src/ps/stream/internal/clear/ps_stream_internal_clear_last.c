/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_clear_last.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:45:27 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/14 23:45:43 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

#include <stdbool.h>

bool	ps_stream_internal_clear_last(t_ps_stream *self)
{
	if (self->tail && ps_stream_internal_clear_last_node(self->tail))
	{
		if (self->tail->prev)
			self->tail->prev->next = NULL;
		else
			self->head = NULL;
		self->tail = self->tail->prev;
		return (true);
	}
	return (false);
}
