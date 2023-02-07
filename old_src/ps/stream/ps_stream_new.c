/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 23:38:14 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/07 23:41:29 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream.h"

#include <stdlib.h>

t_ps_stream	*new_ps_stream(
	size_t a,
	size_t b
)
{
	t_ps_stream *const	result = malloc(sizeof(t_ps_stream));

	if (!result)
		return (NULL);
	result->head = NULL;
	result->tail = NULL;
	result->a = a;
	result->b = b;
	return (result);
}
