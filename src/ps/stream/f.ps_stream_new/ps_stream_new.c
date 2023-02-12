/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_file_name (file name is useless too)          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42header-remover <whatever@example.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by file history     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream.h"

#include <stddef.h>

#include "ps_stream_internal.h"
#include "ds_vector.h"
#include "c.h"

t_ps_stream	*ps_stream_new(size_t a, size_t b)
{
	const t_ps_stream			expose = {
		ds_vector_new(sizeof(t_ps_stream_internal), &ps_stream_internal_free)};
	const t_ps_stream_internal	object = {expose, a, b};
	t_ps_stream_internal		*result;

	if (!expose.vec)
		return (NULL);
	result = c_memdup(&object, sizeof(object));
	if (result)
		return ((t_ps_stream *)result);
	expose.vec->v->dispose(expose.vec);
	return (NULL);
}
