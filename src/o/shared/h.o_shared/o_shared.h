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

#ifndef O_SHARED_H
# define O_SHARED_H

# include "o_disposable.h"

typedef struct s_o_shared
{
	const struct s_o_shared_vtable	*v;
	void *const						p;
}	t_o_shared;

t_o_shared	*o_shared_as_shared(t_o_disposable *disposable);
t_o_shared	*o_shared_make_shared(t_o_disposable *always_consume_disposable);

typedef t_o_shared	*(*t_o_shared_copy)(t_o_shared *self);

typedef struct s_o_shared_vtable
{
	const t_o_disposable_dispose	dispose;
	const t_o_shared_copy			copy;
}	t_o_shared_vtable;

#endif
