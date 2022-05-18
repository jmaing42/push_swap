/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dijkstra_state_can.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:25:28 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/19 02:08:49 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dijkstra.h"

#include <stdlib.h>

#include "ft_malloc.h"

bool	push_swap_dijkstra_state_can(
	t_push_swap_dijkstra_state *self,
	uint8_t length,
	uint8_t operation
)
{
	if (operation == PUSH_SWAP_OPERATION_SA)
		return (push_swap_dijkstra_state_can_sa(self, length));
	if (operation == PUSH_SWAP_OPERATION_SB)
		return (push_swap_dijkstra_state_can_sb(self, length));
	if (operation == PUSH_SWAP_OPERATION_SS)
		return (push_swap_dijkstra_state_can_ss(self, length));
	if (operation == PUSH_SWAP_OPERATION_PA)
		return (push_swap_dijkstra_state_can_pa(self, length));
	if (operation == PUSH_SWAP_OPERATION_PB)
		return (push_swap_dijkstra_state_can_pb(self, length));
	if (operation == PUSH_SWAP_OPERATION_RA)
		return (push_swap_dijkstra_state_can_ra(self, length));
	if (operation == PUSH_SWAP_OPERATION_RB)
		return (push_swap_dijkstra_state_can_rb(self, length));
	if (operation == PUSH_SWAP_OPERATION_RR)
		return (push_swap_dijkstra_state_can_rr(self, length));
	if (operation == PUSH_SWAP_OPERATION_RRA)
		return (push_swap_dijkstra_state_can_rra(self, length));
	if (operation == PUSH_SWAP_OPERATION_RRB)
		return (push_swap_dijkstra_state_can_rrb(self, length));
	if (operation == PUSH_SWAP_OPERATION_RRR)
		return (push_swap_dijkstra_state_can_rrr(self, length));
	return (false);
}
