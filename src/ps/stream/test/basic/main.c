/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:16:38 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/12 20:47:47 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../../ps_stream.h"

t_err	parse_input(char *buffer, t_ps_stream_operation *operation, bool *to_b)
{
	bool	result;

	result = true;
	*to_b = (buffer[1] == 'b' || (buffer[1] == 'r' && buffer[2] == 'a'));
	if (buffer[0] == 'p')
	{
		*operation = PS_STREAM_OPERATION_PUSH;
		result = false;
	}
	if (buffer[0] == 's')
	{
		*operation = PS_STREAM_OPERATION_SWAP;
		result = false;
	}
	if (buffer[0] == 'r')
	{
		*operation = PS_STREAM_OPERATION_ROTATE;
		result = false;
	}
	if (buffer[1] == 'r')
	{
		*operation = PS_STREAM_OPERATION_REVERSE_ROTATE;
		result = false;
	}
	return (result);
}

t_err	test(size_t a, size_t b)
{
	t_ps_stream *const		stream = new_ps_stream(a, b);
	t_ps_stream_operation	operation;
	size_t					count;
	bool					to_b;
	char					buffer[4];

	if (!stream)
		return (true);
	while (!feof(stdin) && scanf("%3s %zu", buffer, &count) == 2)
	{
		if (parse_input(buffer, &operation, &to_b)
			|| ps_stream_append(stream, operation, count, to_b))
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
	size_t					a;
	size_t					b;

	if (argc > 1)
		freopen(argv[1], "r", stdin);
	scanf("%zu %zu", &a, &b);
	if (test(a, b))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
