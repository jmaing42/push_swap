/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_hardcode_execute.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 10:01:03 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/10 10:09:24 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_hardcoded.h"

#include <stdlib.h>
#include <unistd.h>

#include "push_swap_solve_internal.h"

static void	push(char command, bool from_right)
{
	if (command == '\1')
		push_swap_solve_internal_operation_px(1, 0, from_right);
	if (command == '\2')
		push_swap_solve_internal_operation_px(0, 1, from_right);
}

static void	swap(char command, bool from_right)
{
	if (command == '\3')
		push_swap_solve_internal_operation_sx(from_right);
	if (command == '\4')
		push_swap_solve_internal_operation_sx(!from_right);
	if (command == '\5' && ft_write(STDOUT_FILENO, "ss\n", 3))
		ft_exit(EXIT_FAILURE);
}

static void	rotate(char command, bool from_right)
{
	if (command == '\6')
		push_swap_solve_internal_operation_rx(1, 0, from_right);
	if (command == '\7')
		push_swap_solve_internal_operation_rx(0, 1, from_right);
	if (command == '\10')
		push_swap_solve_internal_operation_rx(1, 1, from_right);
}

static void	reverse_rotate(char command, bool from_right)
{
	if (command == '\11')
		push_swap_solve_internal_operation_rrx(1, 0, from_right);
	if (command == '\12')
		push_swap_solve_internal_operation_rrx(0, 1, from_right);
	if (command == '\13')
		push_swap_solve_internal_operation_rrx(1, 1, from_right);
}

void	ps_hardcoded_execute(size_t index, bool from_right, char *const *table)
{
	char	*current;

	current = table[index] - 1;
	while (*++current)
	{
		push(*current, from_right);
		swap(*current, from_right);
		rotate(*current, from_right);
		reverse_rotate(*current, from_right);
	}
}
