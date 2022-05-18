/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:41:01 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/18 13:20:04 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>

#include "ft_malloc.h"

#include "push_swap_max_count.h"

#define TEST_SIZE 1000

int	main(void)
{
	t_push_swap_max_count *const	map = ft_malloc(
			sizeof(t_push_swap_max_count) * TEST_SIZE);
	size_t							i;

	printf("TEST_SIZE: %zu\n", (size_t)TEST_SIZE);
	push_swap_max_count(map, TEST_SIZE, 0, 0);
	i = 0;
	while (i < TEST_SIZE)
	{
		printf("%zu - solution: %" PRIuMAX "; top: %" PRIuMAX
			"; bottom: %" PRIuMAX "\n", i, map[i].solution,
			map[i].part_top, map[i].part_bottom);
		i++;
	}
	return (EXIT_SUCCESS);
}
