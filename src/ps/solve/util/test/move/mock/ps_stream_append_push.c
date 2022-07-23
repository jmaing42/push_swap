/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_append_push.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:49:11 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/23 11:55:38 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream.h"

#include <stdio.h>

t_err	ps_stream_append_pa(t_ps_stream *self, size_t count, bool reverse)
{
	(void)self;
	if (reverse)
		while (count--)
			puts("pb");
	else
		while (count--)
			puts("pa");
	return (false);
}

t_err	ps_stream_append_pb(t_ps_stream *self, size_t count, bool reverse)
{
	(void)self;
	if (reverse)
		while (count--)
			puts("pa");
	else
		while (count--)
			puts("pb");
	return (false);
}
