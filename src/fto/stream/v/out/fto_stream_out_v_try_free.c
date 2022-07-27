/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_out_v_try_free.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 08:52:23 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/26 08:58:26 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_out_v.h"

t_err	fto_stream_out_v_flush(t_fto_stream_out *self)
{
	if (self->v->flush(self))
		return (true);
	self->v->unsafe_free(self);
	return (false);
}
