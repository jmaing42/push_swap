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

#include "util.h"

#include <stddef.h>
#include <assert.h>

int	main(void)
{
	void	*tmp;

	assert(!util_nonnull((void *)&main, &tmp));
	assert(tmp == (void *)&main);
	assert(util_nonnull(NULL, &tmp));
	assert(tmp == (void *)&main);
}
