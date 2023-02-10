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

#include <stdio.h>
#include <stdlib.h>

#include "c.h"

int	main(int argc, char **argv)
{
	t_ps_ints	result;
	char *const	*test = argv;

	if (ps_parse_args(argc, (const char *const *)test, &result))
	{
		puts("KO");
	}
	else
	{
		puts("OK");
		c_free(result.ints);
	}
}
