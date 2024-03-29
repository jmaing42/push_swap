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

#ifndef PS_STREAM_H
# define PS_STREAM_H

# include "ps.h"

# include <stddef.h>

# include "ft_types.h"
# include "ds_vector.h"

typedef struct s_ps_stream
{
	t_ds_vector *const	vec;
}	t_ps_stream;

t_ps_stream	*ps_stream_new(size_t a, size_t b);
t_ds_vector	*ps_stream_to_vector(t_ps_stream *self);
t_err		ps_stream_push(t_ps_stream *self, t_ps_command command);

#endif
