/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dijkstra.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:25:28 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/19 01:56:18 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_DIJKSTRA_H
# define PUSH_SWAP_DIJKSTRA_H

# include <stdbool.h>
# include <stdint.h>

typedef struct s_push_swap_dijkstra_state
{
	uint8_t	size_left;
	uint8_t	values[];
}	t_push_swap_dijkstra_state;

t_push_swap_dijkstra_state		*push_swap_dijkstra_state_empty(
									uint8_t length);
t_push_swap_dijkstra_state		*push_swap_dijkstra_state_top(
									uint8_t length);
t_push_swap_dijkstra_state		*push_swap_dijkstra_state_bottom(
									uint8_t length);
bool							push_swap_dijkstra_state_can(
									t_push_swap_dijkstra_state *self,
									uint8_t length,
									uint8_t operation);
t_push_swap_dijkstra_state		*push_swap_dijkstra_state_do(
									t_push_swap_dijkstra_state *self,
									uint8_t length,
									uint8_t operation);

bool							push_swap_dijkstra_state_can_sa(
									t_push_swap_dijkstra_state *self,
									uint8_t length);
bool							push_swap_dijkstra_state_can_sb(
									t_push_swap_dijkstra_state *self,
									uint8_t length);
bool							push_swap_dijkstra_state_can_ss(
									t_push_swap_dijkstra_state *self,
									uint8_t length);
bool							push_swap_dijkstra_state_can_pa(
									t_push_swap_dijkstra_state *self,
									uint8_t length);
bool							push_swap_dijkstra_state_can_pb(
									t_push_swap_dijkstra_state *self,
									uint8_t length);
bool							push_swap_dijkstra_state_can_ra(
									t_push_swap_dijkstra_state *self,
									uint8_t length);
bool							push_swap_dijkstra_state_can_rb(
									t_push_swap_dijkstra_state *self,
									uint8_t length);
bool							push_swap_dijkstra_state_can_rr(
									t_push_swap_dijkstra_state *self,
									uint8_t length);
bool							push_swap_dijkstra_state_can_rra(
									t_push_swap_dijkstra_state *self,
									uint8_t length);
bool							push_swap_dijkstra_state_can_rrb(
									t_push_swap_dijkstra_state *self,
									uint8_t length);
bool							push_swap_dijkstra_state_can_rrr(
									t_push_swap_dijkstra_state *self,
									uint8_t length);

t_push_swap_dijkstra_state		*push_swap_dijkstra_state_do_sa(
									t_push_swap_dijkstra_state *self,
									uint8_t length);
t_push_swap_dijkstra_state		*push_swap_dijkstra_state_do_sb(
									t_push_swap_dijkstra_state *self,
									uint8_t length);
t_push_swap_dijkstra_state		*push_swap_dijkstra_state_do_ss(
									t_push_swap_dijkstra_state *self,
									uint8_t length);
t_push_swap_dijkstra_state		*push_swap_dijkstra_state_do_pa(
									t_push_swap_dijkstra_state *self,
									uint8_t length);
t_push_swap_dijkstra_state		*push_swap_dijkstra_state_do_pb(
									t_push_swap_dijkstra_state *self,
									uint8_t length);
t_push_swap_dijkstra_state		*push_swap_dijkstra_state_do_ra(
									t_push_swap_dijkstra_state *self,
									uint8_t length);
t_push_swap_dijkstra_state		*push_swap_dijkstra_state_do_rb(
									t_push_swap_dijkstra_state *self,
									uint8_t length);
t_push_swap_dijkstra_state		*push_swap_dijkstra_state_do_rr(
									t_push_swap_dijkstra_state *self,
									uint8_t length);
t_push_swap_dijkstra_state		*push_swap_dijkstra_state_do_rra(
									t_push_swap_dijkstra_state *self,
									uint8_t length);
t_push_swap_dijkstra_state		*push_swap_dijkstra_state_do_rrb(
									t_push_swap_dijkstra_state *self,
									uint8_t length);
t_push_swap_dijkstra_state		*push_swap_dijkstra_state_do_rrr(
									t_push_swap_dijkstra_state *self,
									uint8_t length);

# define PUSH_SWAP_OPERATION_NOP 0
# define PUSH_SWAP_OPERATION_SA 1
# define PUSH_SWAP_OPERATION_SB 2
# define PUSH_SWAP_OPERATION_SS 3
# define PUSH_SWAP_OPERATION_PA 4
# define PUSH_SWAP_OPERATION_PB 5
# define PUSH_SWAP_OPERATION_RA 6
# define PUSH_SWAP_OPERATION_RB 7
# define PUSH_SWAP_OPERATION_RR 8
# define PUSH_SWAP_OPERATION_RRA 9
# define PUSH_SWAP_OPERATION_RRB 10
# define PUSH_SWAP_OPERATION_RRR 11

typedef struct s_push_swap_dijkstra_operations
{
	uint8_t	length;
	uint8_t	values[];
}	t_push_swap_dijkstra_operations;

t_push_swap_dijkstra_operations	*push_swap_operations_new(
									uint8_t value);

t_push_swap_dijkstra_operations	*push_swap_operations_append(
									t_push_swap_dijkstra_operations *self,
									uint8_t value);
t_push_swap_dijkstra_operations	*push_swap_operations_reverse_order(
									t_push_swap_dijkstra_operations *self);
t_push_swap_dijkstra_operations	*push_swap_operations_reverse_rtl(
									t_push_swap_dijkstra_operations *self);

#endif
