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

#ifndef DS_VECTOR_INTERNAL_H
# define DS_VECTOR_INTERNAL_H

# include "ds_vector.h"

# include "ft_types.h"

typedef struct s_ds_vector_internal
{
	t_ds_vector					expose;
	const void					*data;
	const t_ds_vector_free_item	free;
}	t_ds_internal_vector;

size_t	ds_vector_internal_capacity(t_ds_vector *self);
size_t	ds_vector_internal_length(t_ds_vector *self);
t_err	ds_vector_internal_push(t_ds_vector *self, const void *data);
bool	ds_vector_internal_pop(t_ds_vector *self, void *out_data);
bool	ds_vector_internal_peek(t_ds_vector *self, void *out_data);

#endif
