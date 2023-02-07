/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_append_ss.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:44:22 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/14 23:44:22 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

t_err	ps_stream_internal_append_ss(t_ps_stream *self)
{
	return (
		ps_stream_internal_append_sa(self)
		|| ps_stream_internal_append_sb(self)
	);
}
