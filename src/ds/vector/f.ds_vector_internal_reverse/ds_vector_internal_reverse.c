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

#include "ft_types.h"
#include "ds_vector.h"

static void	swap(t_byte *a, t_byte *b, size_t size)
{
	t_byte	tmp;
	size_t	i;

	i = -1;
	while (++i < size)
	{
		tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
	}
}

void	ds_vector_internal_reverse(t_ds_vector *self)
{
	t_ds_vector_internal *const	original = (t_ds_vector_internal *)self;
	const size_t				s = self->item_size;
	size_t						i;

	i = original->length / 2 + 1;
	while (i--)
	{
		swap(
			(t_byte *)original->data + s * i,
			(t_byte *)original->data + s * (original->length - 1 - i),
			s);
	}
}
