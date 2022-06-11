/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:21:13 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/11 22:26:39 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_to_lines.h"

static t_err	ft_to_lines_internal(
	t_ft_to_lines *context,
	char **out_line
)
{
	if (!context->pending)
	{
		out_line = NULL;
		return (false);
	}
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
	context->pending = append;
	context->pending_length = append_length;
	return (ft_to_lines_internal(context, out_line));
}
