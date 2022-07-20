/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_append_pa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:04:14 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/20 20:35:41 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

#include "ft_primitive_size_t.h"

t_err	ps_stream_append_pa(t_ps_stream *self, size_t count, bool reverse)
{
	if (reverse)
		return (ps_stream_internal_append_pb(self, count));
	return (ps_stream_internal_append_pa(self, count));
}
