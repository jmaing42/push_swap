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

#ifndef O_SHARED_INTERNAL_H
# define O_SHARED_INTERNAL_H

# include "o_shared.h"

# include <stddef.h>

# include "ft_types.h"

typedef struct s_o_shared_internal
{
	t_o_shared	expose;
	size_t		reference_count;
}	t_o_shared_internal;

const t_o_shared_vtable	*o_shared_internal_vtable(void);
void					o_shared_internal_dispose(void *self);
t_o_shared				*o_shared_internal_copy(t_o_shared *self);

#endif
