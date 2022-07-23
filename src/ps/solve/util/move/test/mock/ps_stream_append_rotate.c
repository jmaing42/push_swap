/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_append_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:49:11 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/23 11:56:43 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream.h"

#include <stdio.h>

t_err	ps_stream_append_ra(t_ps_stream *self, size_t count, bool reverse)
{
	(void)self;
	if (reverse)
		while (count--)
			puts("rb");
	else
		while (count--)
			puts("ra");
	return (false);
}

t_err	ps_stream_append_rb(t_ps_stream *self, size_t count, bool reverse)
{
	(void)self;
	if (reverse)
		while (count--)
			puts("ra");
	else
		while (count--)
			puts("rb");
	return (false);
}

t_err	ps_stream_append_rr(t_ps_stream *self, size_t count)
{
	(void)self;
	while (count--)
		puts("rr");
	return (false);
}
