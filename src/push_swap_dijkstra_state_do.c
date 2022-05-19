/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dijkstra_state_do.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:25:28 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/20 01:22:11 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dijkstra.h"

#include <stdlib.h>

#include "ft_malloc.h"

void	push_swap_dijkstra_state_do(
	t_push_swap_dijkstra_state *self,
	uint8_t length,
	uint8_t operation,
	t_push_swap_dijkstra_state *out
)
{
	if (operation == PUSH_SWAP_OPERATION_SA)
		return (push_swap_dijkstra_state_do_sa(self, length, out));
	if (operation == PUSH_SWAP_OPERATION_SB)
		return (push_swap_dijkstra_state_do_sb(self, length, out));
	if (operation == PUSH_SWAP_OPERATION_SS)
		return (push_swap_dijkstra_state_do_ss(self, length, out));
	if (operation == PUSH_SWAP_OPERATION_PA)
		return (push_swap_dijkstra_state_do_pa(self, length, out));
	if (operation == PUSH_SWAP_OPERATION_PB)
		return (push_swap_dijkstra_state_do_pb(self, length, out));
	if (operation == PUSH_SWAP_OPERATION_RA)
		return (push_swap_dijkstra_state_do_ra(self, length, out));
	if (operation == PUSH_SWAP_OPERATION_RB)
		return (push_swap_dijkstra_state_do_rb(self, length, out));
	if (operation == PUSH_SWAP_OPERATION_RR)
		return (push_swap_dijkstra_state_do_rr(self, length, out));
	if (operation == PUSH_SWAP_OPERATION_RRA)
		return (push_swap_dijkstra_state_do_rra(self, length, out));
	if (operation == PUSH_SWAP_OPERATION_RRB)
		return (push_swap_dijkstra_state_do_rrb(self, length, out));
	if (operation == PUSH_SWAP_OPERATION_RRR)
		return (push_swap_dijkstra_state_do_rrr(self, length, out));
	exit(EXIT_FAILURE);
}
