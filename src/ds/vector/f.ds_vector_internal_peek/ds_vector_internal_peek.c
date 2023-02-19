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

bool	ds_vector_internal_peek(t_ds_vector *self, void *out_data)
{
	t_ds_vector_internal *const	original = (t_ds_vector_internal *)self;

	if (!original->length)
		return (false);
	return (ds_vector_internal_get(self, original->length - 1, out_data));
}