/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:05:20 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/18 00:07:32 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "ps_stream.h"
#include "ps_solve_internal.h"

static t_err	append(t_ps_stream *stream, const char *direction, bool right)
{
	if (!strcmp(direction, "tsb"))
		return (ps_solve_util_move_tsb(stream, right));
	if (!strcmp(direction, "tot"))
		return (ps_solve_util_move_tot(stream, right));
	if (!strcmp(direction, "tob"))
		return (ps_solve_util_move_tob(stream, right));
	if (!strcmp(direction, "bst"))
		return (ps_solve_util_move_bst(stream, right));
	if (!strcmp(direction, "bot"))
		return (ps_solve_util_move_bot(stream, right));
	if (!strcmp(direction, "bob"))
		return (ps_solve_util_move_bob(stream, right));
	return (true);
}

t_err	test(size_t a, size_t b)
{
	t_ps_stream *const		stream = new_ps_stream(a, b);
	char					buffer[4];
	int						right;
	bool					result;

	if (!stream)
		return (true);
	while (!feof(stdin) && scanf("%3s %d", buffer, &right) == 2)
	{
		if (append(stream, buffer, !!right))
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
	result = ps_stream_print(stream, STDOUT_FILENO);
	ps_stream_free(stream);
	return (result);
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
