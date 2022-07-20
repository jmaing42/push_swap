/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_append_rr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:04:14 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/20 20:35:41 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

#include "ft_primitive_size_t.h"

t_err	ps_stream_append_rr(t_ps_stream *self, size_t count)
{
	return (ps_stream_internal_append_rr(self, count));
}
