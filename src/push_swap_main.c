/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:41:01 by jmaing            #+#    #+#             */
/*   Updated: 2022/06/26 21:37:26 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	init_internal(t_push_swap *self, unsigned int count)
{
	t_push_swap_count_part *const	map = self->map;
	size_t							i;

	if (count < 3)
		return ;
	map[0].sort_only_quick = (t_push_swap_count_item){0, 0, 0, 0};
	map[0].sort_only_merge = (t_push_swap_count_item){0, 0, 0, 0};
	map[0].sort_and_move_quick = (t_push_swap_count_item){0, 0, 0, 0};
	map[0].sort_and_move_merge = (t_push_swap_count_item){0, 0, 0, 0};
	map[1].sort_only_quick = (t_push_swap_count_item){0, 0, 0, 0};
	map[1].sort_only_merge = (t_push_swap_count_item){0, 0, 0, 0};
	map[1].sort_and_move_quick = (t_push_swap_count_item){1, 0, 0, 0};
	map[1].sort_and_move_merge = (t_push_swap_count_item){1, 0, 0, 0};
	map[2].sort_only_quick = (t_push_swap_count_item){1, 0, 0, 0};
	map[2].sort_only_merge = (t_push_swap_count_item){1, 0, 0, 0};
	map[2].sort_and_move_quick = (t_push_swap_count_item){3, 0, 0, 0};
	map[2].sort_and_move_merge = (t_push_swap_count_item){3, 0, 0, 0};
	i = 2;
	while (++i <= count)
		map[i] = push_swap_count_bake_part(map, i);
	self->solution = push_swap_count_solution(map, count);
}

static void	init(
	t_push_swap *self,
	int **out_numbers,
	unsigned int count,
	const char **args
)
{
	int *const						numbers = (int *)
		ft_malloc(sizeof(int) * count);
	t_push_swap_count_part *const	map = (t_push_swap_count_part *)
		ft_malloc(sizeof(t_push_swap_count_part) * (count + 1));
	size_t							i;
	size_t							j;

	self->map = map;
	init_internal(self, count);
	i = -1;
	while (++i < count)
	{
		if (ft_strict_atoi(args[i], &numbers[i]))
			ft_exit(EXIT_FAILURE);
		j = 0;
		while (j < i)
			if (numbers[i] == numbers[j++])
				ft_exit(EXIT_FAILURE);
	}
	*out_numbers = numbers;
}

static void	print_error_message(void)
{
	ft_write(STDOUT_FILENO, "Error\n", 6);
}

int	main(int argc, const char **argv)
{
	t_push_swap		context;
	int				*numbers;
	unsigned int	count;

	ft_set_exit_handler(print_error_message);
	count = argc - 1;
	init(&context, &numbers, count, &argv[1]);
	push_swap_solve(&context, numbers, count);
	return (EXIT_SUCCESS);
}
