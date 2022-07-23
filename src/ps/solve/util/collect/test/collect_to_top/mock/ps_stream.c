/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:49:11 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/23 13:33:12 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream.h"

#include <stdlib.h>

t_ps_stream	*new_ps_stream(size_t a, size_t b)
{
	(void)a;
	(void)b;
	return (malloc(1));
}

void	ps_stream_free(t_ps_stream *self)
{
	free(self);
}

t_err	ps_stream_print(t_ps_stream *self, int fd)
{
	(void)self;
	(void)fd;
	return (false);
}
