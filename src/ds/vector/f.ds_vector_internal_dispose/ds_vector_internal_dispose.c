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

#include <stddef.h>

#include "c.h"

void	ds_vector_internal_dispose(void *self)
{
	t_ds_vector_internal *const	original = (t_ds_vector_internal *)self;
	size_t						i;

	if (original->free)
	{
		i = -1;
		while (++i < original->length)
		{
			original->free(
				&((char *)original->data)[i * original->expose.item_size]);
		}
	}
	c_free(original->data);
	c_free(original);
}
