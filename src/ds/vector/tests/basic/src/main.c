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

#include "ds_vector.h"

#include <stddef.h>
#include <assert.h>

static int	*addressof(int a)
{
	static int	durable;

	durable = a;
	return (&durable);
}

static int	get(t_ds_vector *v, size_t index)
{
	int	result;

	assert(v->v->get(v, index, &result));
	return (result);
}

static int	peek(t_ds_vector *v)
{
	int	result;

	assert(v->v->peek(v, &result));
	return (result);
}

static int	pop(t_ds_vector *v)
{
	int	result;

	assert(v->v->pop(v, &result));
	return (result);
}

int	main(void)
{
	t_ds_vector *const	v = ds_vector_new(sizeof(int), NULL);

	assert(v);
	assert(!v->v->push(v, addressof(42)));
	assert(!v->v->set(v, 1, addressof(4)));
	assert(v->v->set(v, 3, addressof(2)));
	assert(get(v, 0) == 42);
	assert(get(v, 1) == 4);
	assert(!v->v->get(v, 2, addressof(0)));
	assert(peek(v) == 4);
	assert(pop(v) == 4);
	assert(get(v, 0) == 42);
	assert(!v->v->get(v, 1, addressof(0)));
	assert(peek(v) == 42);
	assert(pop(v) == 42);
	assert(!v->v->get(v, 0, addressof(0)));
	assert(!v->v->peek(v, addressof(0)));
	assert(!v->v->pop(v, addressof(0)));
}
