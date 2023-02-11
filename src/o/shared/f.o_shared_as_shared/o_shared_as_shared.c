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

#include "o_shared_internal.h"
#include "o_disposable.h"
#include "c.h"

t_o_shared	*o_shared_as_shared(t_o_disposable *disposable)
{
	const t_o_shared			expose
		= {o_shared_internal_vtable(), disposable};
	const t_o_shared_internal	result = {expose, 1};

	return (c_memdup(&result, sizeof(result)));
}
