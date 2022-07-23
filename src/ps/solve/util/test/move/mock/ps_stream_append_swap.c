/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_append_swap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:49:11 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/23 11:55:32 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream.h"

#include <stdio.h>

t_err	ps_stream_append_sa(t_ps_stream *self, bool reverse)
{
	(void)self;
	if (reverse)
		puts("sb");
	else
		puts("sa");
	return (false);
}

t_err	ps_stream_append_sb(t_ps_stream *self, bool reverse)
{
	(void)self;
	if (reverse)
		puts("sa");
	else
		puts("sb");
	return (false);
}

t_err	ps_stream_append_ss(t_ps_stream *self)
{
	(void)self;
	puts("ss");
	return (false);
}
