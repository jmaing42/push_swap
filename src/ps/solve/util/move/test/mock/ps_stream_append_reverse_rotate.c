/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_append_reverse_rotate.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:49:11 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/23 11:58:46 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream.h"

#include <stdio.h>

t_err	ps_stream_append_rra(t_ps_stream *self, size_t count, bool reverse)
{
	(void)self;
	if (reverse)
		while (count--)
			puts("rrb");
	else
		while (count--)
			puts("rra");
	return (false);
}

t_err	ps_stream_append_rrb(t_ps_stream *self, size_t count, bool reverse)
{
	(void)self;
	if (reverse)
		while (count--)
			puts("rra");
	else
		while (count--)
			puts("rrb");
	return (false);
}

t_err	ps_stream_append_rrr(t_ps_stream *self, size_t count)
{
	(void)self;
	while (count--)
		puts("rrr");
	return (false);
}
