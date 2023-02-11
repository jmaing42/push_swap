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

#include "o_shared_internal.h"

#include "c.h"

void	o_shared_internal_dispose(void *self)
{
	t_o_shared_internal *const	original = (t_o_shared_internal *)self;

	original->reference_count--;
	if (!original->reference_count)
	{
		((t_o_shared *)original->expose.p)->v->dispose(
			(t_o_shared *)original->expose.p);
		c_free(self);
	}
}
