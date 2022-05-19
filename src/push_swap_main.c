/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:41:01 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/19 15:57:38 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>

#include "ft_malloc.h"

#include "push_swap.h"
#include "push_swap_max_count.h"

#define TEST_SIZE 1000

int	main(int argc, char **argv, char **envp)
{
	t_push_swap	context;

	if (push_swap_init(&context, argc, argv, envp))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
