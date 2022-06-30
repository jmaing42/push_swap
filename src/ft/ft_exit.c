/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:10:15 by jmaing            #+#    #+#             */
/*   Updated: 2022/06/27 03:15:36 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exit.h"

#include <stdbool.h>
#include <stdlib.h>

static t_ft_exit_cleanup_function	x(
	bool get,
	t_ft_exit_cleanup_function new_cleanup_function
)
{
	static t_ft_exit_cleanup_function	cleanup_function = NULL;
	static bool							disabled = false;

	if (get && !disabled)
	{
		disabled = true;
		return (cleanup_function);
	}
	cleanup_function = new_cleanup_function;
	return (NULL);
}

int	ft_exit(signed char status)
{
	const t_ft_exit_cleanup_function	cleanup_function = x(true, NULL);

	if (cleanup_function)
		cleanup_function();
	exit((int) status);
}

void	ft_set_exit_handler(t_ft_exit_cleanup_function cleanup_function)
{
	x(false, cleanup_function);
}
