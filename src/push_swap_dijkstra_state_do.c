/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dijkstra_state_do.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:25:28 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/19 02:10:20 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dijkstra.h"

#include <stdlib.h>

#include "ft_malloc.h"

t_push_swap_dijkstra_state	*push_swap_dijkstra_state_do(
	t_push_swap_dijkstra_state *self,
	uint8_t length,
	uint8_t operation
)
{
	if (operation == PUSH_SWAP_OPERATION_SA)
		return (push_swap_dijkstra_state_do_sa(self, length));
	if (operation == PUSH_SWAP_OPERATION_SB)
		return (push_swap_dijkstra_state_do_sb(self, length));
	if (operation == PUSH_SWAP_OPERATION_SS)
		return (push_swap_dijkstra_state_do_ss(self, length));
	if (operation == PUSH_SWAP_OPERATION_PA)
		return (push_swap_dijkstra_state_do_pa(self, length));
	if (operation == PUSH_SWAP_OPERATION_PB)
		return (push_swap_dijkstra_state_do_pb(self, length));
	if (operation == PUSH_SWAP_OPERATION_RA)
		return (push_swap_dijkstra_state_do_ra(self, length));
	if (operation == PUSH_SWAP_OPERATION_RB)
		return (push_swap_dijkstra_state_do_rb(self, length));
	if (operation == PUSH_SWAP_OPERATION_RR)
		return (push_swap_dijkstra_state_do_rr(self, length));
	if (operation == PUSH_SWAP_OPERATION_RRA)
		return (push_swap_dijkstra_state_do_rra(self, length));
	if (operation == PUSH_SWAP_OPERATION_RRB)
		return (push_swap_dijkstra_state_do_rrb(self, length));
	if (operation == PUSH_SWAP_OPERATION_RRR)
		return (push_swap_dijkstra_state_do_rrr(self, length));
	exit(EXIT_FAILURE);
}
