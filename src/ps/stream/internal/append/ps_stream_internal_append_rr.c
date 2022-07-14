/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_append_rr.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:42:53 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/14 23:42:54 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

t_err	ps_stream_internal_append_rr(t_ps_stream *self, size_t count)
{
	return (
		ps_stream_internal_append_ra(self, count)
		|| ps_stream_internal_append_rb(self, count)
	);
}
