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

#include "ps_parse_args.h"

#include <stddef.h>
#include <stdbool.h>

#include "c.h"
#include "ft_types.h"

static t_err	fill(int *dest, size_t count, const char *const *data)
{
	size_t	i;

	i = -1;
	while (++i < count)
		if (ps_parse_args_atoi(data[i], &dest[i]))
			return (true);
	return (false);
}

t_err	ps_parse_args(size_t argc, const char *const *argv, t_ps_ints *out)
{
	const size_t				count = argc - 1;
	const char *const *const	data = argv + 1;
	int *const					ints = c_malloc(sizeof(int) * argc - 1);
	const t_ps_ints				result = {count, ints};

	if (!ints || fill(ints, count, data) || !ps_parse_args_is_uniq(ints, count))
	{
		c_free(ints);
		return (true);
	}
	*out = result;
	return (false);
}
