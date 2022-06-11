/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:41:01 by jmaing            #+#    #+#             */
/*   Updated: 2022/06/11 22:09:12 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_io.h"
#include "ft_exit.h"

#include "checker.h"

static void	print_error_message(void)
{
	ft_write(STDERR_FILENO, "An unknown error occurred.\n", 6);
}

int	main(int argc, char **argv)
{
	t_checker_state *const	state = checker_init(argc - 1, argv + 1);

	(void) state;
	ft_set_exit_handler(print_error_message);
	return (0);
}
