/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:10:15 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/19 16:09:27 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exit.h"

#include <stdbool.h>
#include <stdlib.h>

static void	x(bool execute, void (*cleanup)())
{
	static void	(*cleanup_func)() = NULL;

	if (!execute)
		cleanup_func = cleanup;
	else if (cleanup_func)
		cleanup_func();
}

#ifdef EXIT_PROHIBITED
# ifdef EXIT_ALLOWED
#  error both EXIT_ALLOWED and EXIT_PROHIBITED is defined
# else

int	ft_exit(signed char status)
{
	x(true, NULL);
	return ((int) status);
}

# endif
#else
# ifdef EXIT_ALLOWED

int	ft_exit(signed char status)
{
	x(true, NULL);
	exit((int) status);
}

# else
#  error EXIT_ALLOWED or EXIT_PROHIBITED must be defined
# endif
#endif

void	ft_set_exit_handler(void (*cleanup)())
{
	x(false, cleanup);
}
