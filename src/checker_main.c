/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:41:01 by jmaing            #+#    #+#             */
/*   Updated: 2022/06/13 23:46:13 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "checker.h"

#include "ft_io.h"
#include "ft_memory.h"
#include "ft_to_lines.h"
#include "ft_exit.h"

#define BUFFER_SIZE 1024

#define ERROR_MESSAGE "An unknown error occurred.\n"

static void	print_error_message(void)
{
	ft_write(STDERR_FILENO, ERROR_MESSAGE, sizeof(ERROR_MESSAGE) - 1);
}

static t_err	read_line(
	t_ft_to_lines *context,
	char **out_line,
	bool *out_eof
)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	char	*line;

	*out_eof = false;
	if (ft_to_lines(context, NULL, 0, &line))
		return (true);
	while (!line)
	{
		bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (true);
		if (bytes_read == 0)
		{
			*out_line = ft_to_lines_end(context);
			*out_eof = true;
			return (false);
		}
		else if (ft_to_lines(context, buffer, bytes_read, &line))
			return (true);
	}
	if (!line)
		return (true);
	*out_line = line;
	return (false);
}

int	main(int argc, char **argv)
{
	t_checker_state *const	state = checker_init(argc - 1, argv + 1);
	t_ft_to_lines			context;
	bool					eof;
	char					*line;

	(void) state;
	ft_set_exit_handler(print_error_message);
	ft_bzero(&context, sizeof(context));
	eof = false;
	while (!eof)
	{
		if (read_line(&context, &line, &eof))
			ft_exit(EXIT_FAILURE);
		if (line)
		{
			ft_puts(STDERR_FILENO, line);
			free(line);
		}
	}
	return (EXIT_FAILURE);
}
