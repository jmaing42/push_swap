/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:16:38 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/11 22:01:49 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include "../../ps_stream.h"

int	main(void)
{
	t_ps_stream *const	stream = new_ps_stream(10, 5);

	ps_stream_append(stream, PS_STREAM_OPERATION_PUSH, 100, true);
	ps_stream_print(stream, STDOUT_FILENO);
	ps_stream_free(stream);
}
