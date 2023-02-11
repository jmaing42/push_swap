/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds_vector_internal_set.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:00:26 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/02/12 03:35:17 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ds_vector_internal.h"

#include <stddef.h>

#include "ds_vector.h"
#include "ft_types.h"
#include "c.h"

t_err	ds_vector_internal_set(
	t_ds_vector *self,
	size_t index,
	const void *data
)
{
	t_ds_vector_internal *const	original = (t_ds_vector_internal *)self;

	if (index == original->length)
		return (ds_vector_internal_push(self, data));
	if (index > original->length)
		return (true);
	c_memcpy(
		&((char *)original->data)[index * self->item_size],
		data,
		self->item_size);
	return (false);
}
