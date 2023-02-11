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

#include "o_shared.h"

#include <stdio.h>
#include <assert.h>

#include "c.h"
#include "o_disposable.h"
#include "util.h"

static const t_o_disposable_vtable	g_vtable = {&util_noop};

static t_o_disposable	*create_dumb_disposable(void)
{
	const t_o_disposable	result = {&g_vtable};

	return (c_memdup(&result, sizeof(result)));
}

int	main(void)
{
	t_o_disposable	*a;
	t_o_shared		*b;
	t_o_shared		*c;
	t_o_shared		*d;
	t_o_shared		*e;

	assert(a = create_dumb_disposable());
	assert(b = o_shared_as_shared(a));
	assert(c = b->v->copy(b));
	b->v->dispose(b);
	assert(d = c->v->copy(c));
	c->v->dispose(c);
	assert(e = d->v->copy(d));
	d->v->dispose(d);
	assert(puts("should not be freed yet") != EOF);
	assert(e->p == a);
	e->v->dispose(e);
	assert(puts("should be free") != EOF);
}
