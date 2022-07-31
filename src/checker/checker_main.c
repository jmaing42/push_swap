/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:41:01 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 15:32:52 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "checker.h"

#include "ft_io.h"
#include "ft_memory.h"
#include "ft_to_lines.h"
#include "ft_exit.h"

#define BUFFER_SIZE 1024

#define ERROR_MESSAGE "Error: an unknown error occurred.\n"

static void	print_error_message(void)
{
	ft_write(STDERR_FILENO, ERROR_MESSAGE, sizeof(ERROR_MESSAGE) - 1);
}

static t_err	read_line(
	t_ft_to_lines *context,
	char **out_line,
	size_t *out_length,
	bool *out_eof
)
{
	static char	buffer[BUFFER_SIZE];
	ssize_t		bytes_read;

	*out_eof = false;
	if (ft_to_lines_drain(context, out_line, out_length))
		return (true);
	while (!*out_line)
	{
		bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (true);
		if (!bytes_read)
		{
			*out_eof = true;
			if (ft_to_lines_get_current_line(context, out_line, out_length))
				return (true);
			ft_to_lines_free(context);
			return (false);
		}
		if (ft_to_lines_feed(context, buffer, bytes_read)
			|| ft_to_lines_drain(context, out_line, out_length))
			return (true);
	}
	return (false);
}

int	main(int argc, char **argv)
{
	t_ps_stack *const	state = checker_init(argc - 1, argv + 1);
	t_ft_to_lines		context;
	bool				eof;
	char				*line;
	size_t				nop;

	context.buffer_size = BUFFER_SIZE;
	ft_set_exit_handler(print_error_message);
	ft_bzero(&context, sizeof(context));
	eof = false;
	while (!eof)
	{
		if (read_line(&context, &line, &nop, &eof))
			ft_exit(EXIT_FAILURE);
		if (line)
		{
			if (checker_do(state, line))
				checker_exit("Error: invalid operation given.");
			free(line);
		}
	}
	checker_finalize(state);
}
