/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_finalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 00:04:42 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/14 00:17:05 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

#include <unistd.h>

#include "ft_io.h"
#include "ft_exit.h"

void	checker_finalize(t_checker_state *self)
{
	if (checker_sorted(self))
	{
		if (ft_puts(STDOUT_FILENO, "OK\n"))
			ft_exit(EXIT_FAILURE);
	}
	else
	{
		if (ft_puts(STDOUT_FILENO, "KO\n"))
			ft_exit(EXIT_FAILURE);
	}
	ft_set_exit_handler(NULL);
	ft_exit(EXIT_SUCCESS);
}
