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

#include "ds_vector_internal.h"

#include "ds_vector.h"
#include "c.h"

t_err	ds_vector_internal_append(t_ds_vector *self, t_ds_vector *source)
{
	t_byte *const	tmp = c_malloc(self->item_size);
	size_t			i;

	if (!tmp)
		return (true);
	i = -1;
	while (++i < source->v->length(source))
	{
		source->v->get(source, i, tmp);
		if (self->v->push(self, tmp))
		{
			c_free(tmp);
			return (true);
		}
	}
	c_free(tmp);
	return (false);
}
