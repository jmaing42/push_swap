/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:41:01 by jmaing            #+#    #+#             */
/*   Updated: 2022/07/23 13:31:20 by Juyeong Maing    ###   ########.fr       */
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

static void	init(
	int **out_numbers,
	unsigned int count,
	const char **args
)
{
	int *const						numbers = (int *)
		ft_malloc(sizeof(int) * count);
	size_t							i;
	size_t							j;

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
	int				*numbers;
	unsigned int	count;

	ft_set_exit_handler(print_error_message);
	count = argc - 1;
	init(&numbers, count, &argv[1]);
	push_swap_solve(numbers, count);
	return (EXIT_SUCCESS);
}
