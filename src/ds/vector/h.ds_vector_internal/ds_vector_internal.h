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
	void						*data;
	size_t						capacity;
	size_t						length;
	const t_ds_vector_free_item	free;
}	t_ds_vector_internal;

void	ds_vector_internal_dispose(
			void *self);
size_t	ds_vector_internal_capacity(
			t_ds_vector *self);
size_t	ds_vector_internal_length(
			t_ds_vector *self);
t_err	ds_vector_internal_push(
			t_ds_vector *self,
			const void *data);
bool	ds_vector_internal_pop(
			t_ds_vector *self,
			void *out_data);
bool	ds_vector_internal_peek(
			t_ds_vector *self,
			void *out_data);
t_err	ds_vector_internal_set(
			t_ds_vector *self,
			size_t index,
			const void *data);
bool	ds_vector_internal_get(
			t_ds_vector *self,
			size_t index,
			void *out_data);

#endif
