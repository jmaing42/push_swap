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

#include "wrap.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

void	wrap_free(void *memory)
{
	bool	error;

	if (memory)
	{
		error = (puts("free") == EOF);
		assert(!error);
	}
	free(memory);
}
