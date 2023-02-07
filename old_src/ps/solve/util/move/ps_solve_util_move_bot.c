/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_move_bot.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 00:53:21 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/17 00:59:27 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

t_err	ps_solve_util_move_bot(
	t_ps_stream *stream,
	bool from_right
)
{
	return (
		ps_stream_append_rra(stream, 1, from_right)
		|| ps_stream_append_pb(stream, 1, from_right)
	);
}
