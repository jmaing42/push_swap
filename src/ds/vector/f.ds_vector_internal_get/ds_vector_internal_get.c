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

#include <stdbool.h>

#include "ds_vector.h"
#include "c.h"

bool	ds_vector_internal_get(t_ds_vector *self, size_t index, void *out_data)
{
	t_ds_vector_internal *const	original = (t_ds_vector_internal *)self;

	if (original->length <= index)
		return (false);
	c_memcpy(
		out_data,
		&((char *)original->data)[index * self->item_size],
		self->item_size);
	return (true);
}
