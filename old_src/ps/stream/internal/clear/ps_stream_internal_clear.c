/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_clear.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:45:27 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/15 00:39:03 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

#include <stdbool.h>

void	ps_stream_internal_clear(t_ps_stream *self)
{
	t_ps_stream_node	*prev;

	if (!self->tail)
		return ;
	prev = self->tail->prev;
	if (!ps_stream_internal_clear_node(self->tail))
		return ;
	if (prev)
		prev->next = NULL;
	else
		self->head = NULL;
	self->tail = prev;
}
