/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_move_tob.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 00:53:21 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/17 00:58:32 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

t_err	ps_solve_util_move_tob(
	t_ps_stream *stream,
	bool from_right
)
{
	return (
		ps_stream_append_pb(stream, 1, from_right)
		|| ps_stream_append_rb(stream, 1, from_right)
	);
}
