/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_append_rrr.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:43:38 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/14 23:43:41 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

t_err	ps_stream_internal_append_rrr(t_ps_stream *self, size_t count)
{
	return (
		ps_stream_internal_append_rra(self, count)
		|| ps_stream_internal_append_rrb(self, count)
	);
}
