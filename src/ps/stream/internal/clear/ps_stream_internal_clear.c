/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_clear.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:45:24 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/14 23:45:24 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

void	ps_stream_internal_clear(t_ps_stream *self)
{
	while (ps_stream_internal_clear_last(self))
		;
}
