/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:16:38 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/12 21:14:20 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "ps_stream.h"

static t_err	append_swap(
	t_ps_stream *stream,
	const char *operation,
	size_t count
)
{
	size_t	i;

	i = -1;
	if (!strcmp(operation, "sa"))
	{
		while (++i < count)
			if (ps_stream_append_sa(stream, false))
				return (true);
	}
	else if (!strcmp(operation, "sb"))
	{
		while (++i < count)
			if (ps_stream_append_sb(stream, false))
				return (true);
	}
	else if (!strcmp(operation, "ss"))
	{
		while (++i < count)
			if (ps_stream_append_ss(stream))
				return (true);
	}
	else
		return (true);
	return (false);
}

static t_err	append(t_ps_stream *stream, const char *operation, size_t count)
{
	if (!strcmp(operation, "pa"))
		return ps_stream_append_pa(stream, count, false);
	if (!strcmp(operation, "pb"))
		return ps_stream_append_pb(stream, count, false);
	if (!strcmp(operation, "ra"))
		return ps_stream_append_ra(stream, count, false);
	if (!strcmp(operation, "rb"))
		return ps_stream_append_rb(stream, count, false);
	if (!strcmp(operation, "rr"))
		return ps_stream_append_rr(stream, count);
	if (!strcmp(operation, "rra"))
		return ps_stream_append_rra(stream, count, false);
	if (!strcmp(operation, "rrb"))
		return ps_stream_append_rrb(stream, count, false);
	if (!strcmp(operation, "rrr"))
		return ps_stream_append_rrr(stream, count);
	return (append_swap(stream, operation, count));
}

t_err	test(size_t a, size_t b)
{
	t_ps_stream *const		stream = new_ps_stream(a, b);
	size_t					count;
	char					buffer[4];

	if (!stream)
		return (true);
	while (!feof(stdin) && scanf("%3s %zu", buffer, &count) == 2)
	{
		if (append(stream, buffer, count))
		{
			ps_stream_free(stream);
			return (true);
		}
	}
	if (!feof(stdin))
	{
		ps_stream_free(stream);
		return (true);
	}
	ps_stream_print(stream, STDOUT_FILENO);
	ps_stream_free(stream);
	return (false);
}

int	main(int argc, char **argv)
{
	size_t	a;
	size_t	b;

	if (argc > 1)
		freopen(argv[1], "r", stdin);
	scanf("%zu %zu", &a, &b);
	if (test(a, b))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
