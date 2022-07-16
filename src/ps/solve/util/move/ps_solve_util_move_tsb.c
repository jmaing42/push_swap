/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve_util_move_tsb.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 00:53:21 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/17 00:56:01 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_solve_internal.h"

t_err	ps_solve_util_move_tsb(
	t_ps_stream *stream,
	bool from_right
)
{
	return (
		ps_stream_append_ra(stream, 1, from_right)
	);
}
