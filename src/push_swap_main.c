/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:41:01 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/25 13:50:00 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>

#include "ft_malloc.h"
#include "ft_io.h"
#include "ft_exit.h"
#include "ft_strict_atoi.h"

#include "push_swap_count.h"
#include "push_swap_solve.h"

#define TEST_SIZE 1000

static void	init_internal(t_push_swap *self, int count)
{
	t_push_swap_count_part *const	map = self->map;
	size_t							i;

	map[0].sort_only_divide_first = (t_push_swap_count_item){0, 0, 0, 0};
	map[0].sort_only_collect_last = (t_push_swap_count_item){0, 0, 0, 0};
	map[0].sort_and_move_divide_first = (t_push_swap_count_item){0, 0, 0, 0};
	map[0].sort_and_move_collect_last = (t_push_swap_count_item){0, 0, 0, 0};
	map[1].sort_only_divide_first = (t_push_swap_count_item){0, 0, 0, 0};
	map[1].sort_only_collect_last = (t_push_swap_count_item){0, 0, 0, 0};
	map[1].sort_and_move_divide_first = (t_push_swap_count_item){1, 0, 0, 0};
	map[1].sort_and_move_collect_last = (t_push_swap_count_item){1, 0, 0, 0};
	map[2].sort_only_divide_first = (t_push_swap_count_item){1, 0, 0, 0};
	map[2].sort_only_collect_last = (t_push_swap_count_item){1, 0, 0, 0};
	map[2].sort_and_move_divide_first = (t_push_swap_count_item){3, 0, 0, 0};
	map[2].sort_and_move_collect_last = (t_push_swap_count_item){3, 0, 0, 0};
	i = 2;
	while (++i <= count)
		map[i] = push_swap_count_bake_part(map, i);
	self->solution = push_swap_count_solution(map, count);
}

static t_err	init(t_push_swap *self, unsigned int count, const char **args)
{
	int *const						numbers = (int *)
		ft_malloc(sizeof(int) * count);
	t_push_swap_count_part *const	map = (t_push_swap_count_part *)
		ft_malloc(sizeof(t_push_swap_count_part) * count + 1);
	size_t							i;
	size_t							j;

	self->map = map;
	init_internal(self, count);
	i = -1;
	while (++i < count)
	{
		if (ft_strict_atoi(args[i], &numbers[i]))
			return (ft_exit(EXIT_FAILURE));
		j = 0;
		while (j < i)
			if (numbers[i] == numbers[j++])
				return (ft_exit(EXIT_FAILURE));
	}
	return (false);
}

static void	print_error_message(void)
{
	ft_write(STDOUT_FILENO, "Error\n", 6);
}

int	main(int argc, const char **argv)
{
	t_push_swap	context;

	ft_set_exit_handler(print_error_message);
	if (init(&context, argc - 1, &argv[1]))
		return (EXIT_FAILURE);
	push_swap_solve(&context);
	return (EXIT_SUCCESS);
}
