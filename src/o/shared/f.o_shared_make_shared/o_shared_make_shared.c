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

#include "o_shared.h"

t_o_shared	*o_shared_make_shared(t_o_disposable *always_consume_disposable)
{
	t_o_shared *const	result = o_shared_as_shared(always_consume_disposable);

	if (!result)
		always_consume_disposable->v->dispose(always_consume_disposable);
	return (result);
}
