/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:41:01 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/18 17:15:04 by Juyeong Maing    ###   ########.fr       */
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
		printf("%zu\n", i);
		printf("\tsolution: %" PRIuMAX "(%" PRIuMAX ", %" PRIuMAX ", %" PRIuMAX ")\n", map[i].solution, map[i].solution_a_top, map[i].solution_b_top, map[i].solution_b_bottom);
		printf("\ttop: %" PRIuMAX "(%" PRIuMAX ", %" PRIuMAX ", %" PRIuMAX ")\n", map[i].part_top, map[i].part_top_self_bottom, map[i].part_top_other_top, map[i].part_top_other_bottom);
		printf("\tbottom: %" PRIuMAX "(%" PRIuMAX ", %" PRIuMAX ", %" PRIuMAX ")\n", map[i].part_bottom, map[i].part_bottom_self_top, map[i].part_bottom_other_top, map[i].part_bottom_other_bottom);
		i++;
	}
	return (EXIT_SUCCESS);
}
