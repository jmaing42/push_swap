/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/02/19 07:44:44 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream.h"

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "ps.h"
#include "ft_types.h"
#include "ds_vector.h"
#include "o_disposable.h"

static t_err	push(t_ps_stream *stream, const char *name)
{
	if (!strcmp("pa", name))
		return (ps_stream_push(stream, PS_PA));
	if (!strcmp("pb", name))
		return (ps_stream_push(stream, PS_PB));
	if (!strcmp("sa", name))
		return (ps_stream_push(stream, PS_SA));
	if (!strcmp("sb", name))
		return (ps_stream_push(stream, PS_SB));
	if (!strcmp("ss", name))
		return (ps_stream_push(stream, PS_SS));
	if (!strcmp("ra", name))
		return (ps_stream_push(stream, PS_RA));
	if (!strcmp("rb", name))
		return (ps_stream_push(stream, PS_RB));
	if (!strcmp("rs", name))
		return (ps_stream_push(stream, PS_RR));
	if (!strcmp("rra", name))
		return (ps_stream_push(stream, PS_RRA));
	if (!strcmp("rrb", name))
		return (ps_stream_push(stream, PS_RRB));
	if (!strcmp("rrs", name))
		return (ps_stream_push(stream, PS_RRR));
	return (true);
}

static void	print(t_ds_vector *vec, size_t index)
{
	t_ps_command	command;

	assert(vec->v->get(vec, index, &command));
	if (command == PS_PA)
		assert(puts("pa") != EOF);
	else if (command == PS_PB)
		assert(puts("pb") != EOF);
	else if (command == PS_SA)
		assert(puts("sa") != EOF);
	else if (command == PS_SB)
		assert(puts("sb") != EOF);
	else if (command == PS_SS)
		assert(puts("ss") != EOF);
	else if (command == PS_RA)
		assert(puts("ra") != EOF);
	else if (command == PS_RB)
		assert(puts("rb") != EOF);
	else if (command == PS_RR)
		assert(puts("rr") != EOF);
	else if (command == PS_RRA)
		assert(puts("rra") != EOF);
	else if (command == PS_RRB)
		assert(puts("rrb") != EOF);
	else
		assert(puts("rrr") != EOF);
}

int	main(void)
{
	char		buffer[4];
	t_ps_stream	*stream;
	size_t		tmp_a;
	size_t		tmp_b;
	t_ds_vector	*result;

	assert(scanf("%zu %zu", &tmp_a, &tmp_b) == 2);
	assert(stream = ps_stream_new(tmp_a, tmp_b));
	while (!feof(stdin) && !ferror(stdin))
		assert(
			(scanf("%3s", buffer) == 1 || feof(stdin))
			&& !ferror(stdin)
			&& !push(stream, buffer));
	assert(!ferror(stdin));
	assert(result = ps_stream_to_vector(stream));
	tmp_a = -1;
	while (++tmp_a < result->v->length(result))
		print(result, tmp_a);
	o_disposable_dispose((t_o_disposable *)result);
}
