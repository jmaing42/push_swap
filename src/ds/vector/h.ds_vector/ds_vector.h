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

#ifndef DS_VECTOR_H
# define DS_VECTOR_H

# include <stddef.h>
# include <stdbool.h>

# include "ft_types.h"
# include "o_disposable.h"

typedef void	(*t_ds_vector_free_item)(void *item);

typedef struct s_ds_vector
{
	const struct s_ds_vector_vtable	*vtable;
	const size_t					item_size;
}	t_ds_vector;

t_ds_vector	*ds_vector_new(size_t item_size, t_ds_vector_free_item free);

typedef size_t	(*t_ds_vector_capacity)(t_ds_vector *self);
typedef size_t	(*t_ds_vector_length)(t_ds_vector *self);
typedef t_err	(*t_ds_vector_push)(t_ds_vector *self, const void *data);
typedef bool	(*t_ds_vector_pop)(t_ds_vector *self, void *out_data);
typedef bool	(*t_ds_vector_peek)(t_ds_vector *self, void *out_data);

typedef struct s_ds_vector_vtable
{
	const t_o_disposable_dispose	dispose;
	const t_ds_vector_capacity		capacity;
	const t_ds_vector_length		length;
	const t_ds_vector_push			push;
	const t_ds_vector_pop			pop;
	const t_ds_vector_peek			peek;
}	t_ds_vector_vtable;

#endif
