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

#include "ds_vector.h"

#include "ds_vector_internal.h"
#include "c.h"

static const t_ds_vector_vtable	g_vtable = {
	&ds_vector_internal_dispose,
	&ds_vector_internal_capacity,
	&ds_vector_internal_length,
	&ds_vector_internal_push,
	&ds_vector_internal_pop,
	&ds_vector_internal_peek,
};

t_ds_vector	*ds_vector_new(size_t item_size, t_ds_vector_free_item free)
{
	const t_ds_vector			expose = {&g_vtable, item_size};
	const t_ds_vector_internal	result = {expose, NULL, 0, 0, free};

	return ((t_ds_vector *)c_memdup(&result, sizeof(result)));
}
