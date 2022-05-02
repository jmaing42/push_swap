/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_byte_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:54:01 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/02 14:59:13 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>

#include "ft_byte_map.h"

void	ft_byte_map(const t_byte *set, t_byte *map, bool include_null)
{
	size_t			i;
	const t_byte	*tmp;

	i = 0;
	while (i < 1 << CHAR_BIT)
		map[i++] = 0;
	if (include_null || !set)
		map[0] = 1;
	if (!set)
		return ;
	tmp = (const unsigned char *) set;
	while (*tmp)
		map[*tmp++] = 1;
}
