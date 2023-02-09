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

#include "c.h"

#include <stddef.h>

void	*c_memcpy(void *dest, const void *source, size_t len)
{
	char	*src;
	char	*dst;

	src = (char *) source;
	dst = (char *) dest;
	while (len--)
		*dst++ = *src++;
	return (dest);
}
