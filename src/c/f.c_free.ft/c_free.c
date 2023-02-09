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

#include "wrap.h"
#include "c_internal.h"

void	c_free(void *ptr)
{
	t_c_memory_block	*old;

	if (!ptr)
		return ;
	old = (t_c_memory_block *)((intptr_t)(ptr)
			- (intptr_t)(&((t_c_memory_block *) 0)->actual));
	wrap_free(old);
}
