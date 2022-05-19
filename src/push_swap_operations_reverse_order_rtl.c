/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_reverse_order_rtl.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 01:34:05 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/20 01:52:17 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dijkstra.h"

#include <stdlib.h>

#include "ft_malloc.h"
#include "ft_memory.h"
#include "ft_exit.h"

static uint8_t	reverse(uint8_t operation)
{
	if (operation == PUSH_SWAP_OPERATION_SA)
		return (PUSH_SWAP_OPERATION_SB);
	if (operation == PUSH_SWAP_OPERATION_SB)
		return (PUSH_SWAP_OPERATION_SA);
	if (operation == PUSH_SWAP_OPERATION_SS)
		return (PUSH_SWAP_OPERATION_SS);
	if (operation == PUSH_SWAP_OPERATION_PA)
		return (PUSH_SWAP_OPERATION_PA);
	if (operation == PUSH_SWAP_OPERATION_PB)
		return (PUSH_SWAP_OPERATION_PB);
	if (operation == PUSH_SWAP_OPERATION_RA)
		return (PUSH_SWAP_OPERATION_RRB);
	if (operation == PUSH_SWAP_OPERATION_RB)
		return (PUSH_SWAP_OPERATION_RRA);
	if (operation == PUSH_SWAP_OPERATION_RR)
		return (PUSH_SWAP_OPERATION_RRR);
	if (operation == PUSH_SWAP_OPERATION_RRA)
		return (PUSH_SWAP_OPERATION_RB);
	if (operation == PUSH_SWAP_OPERATION_RRB)
		return (PUSH_SWAP_OPERATION_RA);
	if (operation == PUSH_SWAP_OPERATION_RRR)
		return (PUSH_SWAP_OPERATION_RR);
	ft_exit(EXIT_FAILURE);
}

t_push_swap_dijkstra_operations	*push_swap_operations_reverse_order_rtl(
	t_push_swap_dijkstra_operations *self
)
{
	t_push_swap_dijkstra_operations *const	result
		= (t_push_swap_dijkstra_operations *)ft_malloc(
			sizeof(t_push_swap_dijkstra_operations)
			+ sizeof(uint8_t) * (self->length + 1));
	size_t									i;

	i = 0;
	while (i < self->length)
	{
		result->operation[i] = reverse(self->operation[self->length - i - 1]);
		i++;
	}
	result->length = self->length;
	return (result);
}
