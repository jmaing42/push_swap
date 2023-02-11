/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds_vector_internal_push.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:00:26 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/02/12 03:21:20 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ds_vector_internal.h"

#include <stddef.h>

#include "ds_vector.h"
#include "ft_types.h"
#include "c.h"

static size_t	next_capacity(size_t capacity)
{
	if (!capacity)
		return (10);
	return (capacity * 2);
}

static t_err	increase_capacity_if_needed(t_ds_vector_internal *self)
{
	size_t	capacity;
	void	*data;

	if (self->capacity != self->length)
		return (false);
	capacity = next_capacity(self->capacity);
	data = c_malloc(capacity * self->expose.item_size);
	if (!data)
		return (true);
	c_memcpy(data, self->data, self->length * self->expose.item_size);
	c_free(self->data);
	self->data = data;
	self->capacity = capacity;
	return (false);
}

t_err	ds_vector_internal_push(t_ds_vector *self, const void *data)
{
	t_ds_vector_internal *const	original = (t_ds_vector_internal *)self;

	if (increase_capacity_if_needed(original))
		return (true);
	c_memcpy(
		&((char *)original->data)[original->length * self->item_size],
		data,
		self->item_size);
	original->length++;
	return (false);
}
