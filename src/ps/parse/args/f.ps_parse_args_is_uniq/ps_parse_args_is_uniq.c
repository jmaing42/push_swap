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

#include <stdbool.h>

bool	ps_parse_args_is_uniq(const int *ints, size_t count)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < count)
	{
		j = -1;
		while (++j < i)
		{
			if (ints[i] == ints[j])
				return (false);
		}
	}
	return (true);
}

