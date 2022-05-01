/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer_fd_internal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:58:15 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/01 21:43:58 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_writer_fd_internal.h"

#include <stdlib.h>
#include <unistd.h>

#include "ft_io.h"
#include "ft_writer_internal.h"

static void	writer_unsafe_close(t_writer_fd *self)
{
	if (self->close_fd_on_delete)
		close(self->fd);
	free(self);
}

static t_err	writer_write(
	t_writer_fd *self,
	const void *buffer,
	size_t len,
	t_exception **exception
)
{
	if (ft_write(self->fd, buffer, len, exception))
	{
		if (exception && *exception)
			(*exception)->v->add_stacktrace(
				*exception, __FILE__, __LINE__, NULL);
		return (true);
	}
	return (false);
}

static const t_writer_vtable	g_v = {
	(t_writer_v_unsafe_close)(&writer_unsafe_close),
	(t_writer_v_write)(&writer_write),
	(t_writer_v_flush)(&ft_writer_base_v_default_flush),
	(t_writer_v_close)(&ft_writer_base_v_default_close)
};

t_writer	*new_writer_fd(int fd, bool close_fd_on_delete)
{
	t_writer_fd *const	result = (t_writer_fd *) malloc(sizeof(t_writer_fd));

	if (!result)
		return (NULL);
	result->expose.v = &g_v;
	result->fd = fd;
	result->close_fd_on_delete = close_fd_on_delete;
	return ((t_writer *) result);
}
