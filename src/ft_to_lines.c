/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:21:13 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/13 02:20:50 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_to_lines.h"

#include "ft_memory.h"

static t_err	ft_to_lines_internal_append(
	t_ft_to_lines *context,
	char **out_line
)
{
	if (stringbuilder_append(
			context->current,
			context->pending_length - context->pending_offset,
			&context->pending[context->pending_offset]))
		return (true);
	context->pending = NULL;
	*out_line = NULL;
	return (false);
}

static t_err	ft_to_lines_internal_final(
	t_ft_to_lines *context,
	char **out_line,
	size_t position
)
{
	if (stringbuilder_append(
			context->current,
			position,
			&context->pending[context->pending_offset]))
		return (true);
	*out_line = stringbuilder_to_string(context->current, 0);
	if (!*out_line)
		return (true);
	stringbuilder_free(context->current);
	context->current = NULL;
	return (false);
}

static t_err	ft_to_lines_internal(
	t_ft_to_lines *context,
	char **out_line
)
{
	size_t	position;

	if (!context->pending)
	{
		*out_line = NULL;
		return (false);
	}
	if (ft_memory_find(
			&context->pending[context->pending_offset],
			context->pending_length - context->pending_offset,
			'\n',
			&position))
		return (ft_to_lines_internal_final(context, out_line, position));
	return (ft_to_lines_internal_append(context, out_line));
}

t_err	ft_to_lines(
	t_ft_to_lines *context,
	const void *append,
	size_t append_length,
	char **out_line
)
{
	if (!append || !append_length)
		return (ft_to_lines_internal(context, out_line));
	if (append && context->pending)
		return (true);
	context->pending = (const char *)append;
	context->pending_length = append_length;
	return (ft_to_lines_internal(context, out_line));
}
