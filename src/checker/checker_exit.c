/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:18:29 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/11 22:03:29 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

#include <unistd.h>

#include "ft_io.h"
#include "ft_exit.h"

int	checker_exit(const char *message)
{
	if (message)
	{
		ft_puts(STDERR_FILENO, message);
		ft_write(STDERR_FILENO, "\n", 1);
	}
	ft_set_exit_handler(NULL);
	return (ft_exit(EXIT_FAILURE));
}
