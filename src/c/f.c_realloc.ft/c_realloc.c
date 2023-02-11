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
#include <stdint.h>

#include "c_internal.h"

void	*c_realloc(void *ptr, size_t size)
{
	t_c_memory_block	*old;
	void				*result;

	if (!ptr)
		return (c_malloc(size));
	old = (t_c_memory_block *)((intptr_t)(ptr)
			- (intptr_t)(&((t_c_memory_block *) 0)->actual));
	if (old->capacity < size)
	{
		result = c_malloc(size);
		if (result)
			c_memcpy(result, ptr, size);
		c_free(old);
		return (result);
	}
	else
	{
		old->size = size;
		return (ptr);
	}
}
