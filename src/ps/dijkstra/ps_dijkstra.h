/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_dijkstra.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:25:28 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/01 00:22:50 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_DIJKSTRA_H
# define PS_DIJKSTRA_H

# include <stdbool.h>
# include <stdint.h>

# include "ft_simple_map.h"

typedef struct s_ps_dijkstra_state
{
	uint8_t	size_left;
	uint8_t	values[];
}	t_ps_dijkstra_state;

t_ps_dijkstra_state			*ps_dijkstra_state_new(
								uint8_t length);
t_ps_dijkstra_state			*ps_dijkstra_state_top(
								uint8_t length);
t_ps_dijkstra_state			*ps_dijkstra_state_bottom(
								uint8_t length);
bool						ps_dijkstra_state_can(
								t_ps_dijkstra_state *self,
								uint8_t length,
								uint8_t operation);
void						ps_dijkstra_state_do(
								t_ps_dijkstra_state *self,
								uint8_t length,
								uint8_t operation,
								t_ps_dijkstra_state *out);

bool						ps_dijkstra_state_can_pa(
								t_ps_dijkstra_state *self,
								uint8_t length);
bool						ps_dijkstra_state_can_pb(
								t_ps_dijkstra_state *self,
								uint8_t length);
bool						ps_dijkstra_state_can_sa(
								t_ps_dijkstra_state *self,
								uint8_t length);
bool						ps_dijkstra_state_can_sb(
								t_ps_dijkstra_state *self,
								uint8_t length);
bool						ps_dijkstra_state_can_ss(
								t_ps_dijkstra_state *self,
								uint8_t length);
bool						ps_dijkstra_state_can_ra(
								t_ps_dijkstra_state *self,
								uint8_t length);
bool						ps_dijkstra_state_can_rb(
								t_ps_dijkstra_state *self,
								uint8_t length);
bool						ps_dijkstra_state_can_rr(
								t_ps_dijkstra_state *self,
								uint8_t length);
bool						ps_dijkstra_state_can_rra(
								t_ps_dijkstra_state *self,
								uint8_t length);
bool						ps_dijkstra_state_can_rrb(
								t_ps_dijkstra_state *self,
								uint8_t length);
bool						ps_dijkstra_state_can_rrr(
								t_ps_dijkstra_state *self,
								uint8_t length);

void						ps_dijkstra_state_do_pa(
								t_ps_dijkstra_state *self,
								uint8_t length,
								t_ps_dijkstra_state *out);
void						ps_dijkstra_state_do_pb(
								t_ps_dijkstra_state *self,
								uint8_t length,
								t_ps_dijkstra_state *out);
void						ps_dijkstra_state_do_sa(
								t_ps_dijkstra_state *self,
								uint8_t length,
								t_ps_dijkstra_state *out);
void						ps_dijkstra_state_do_sb(
								t_ps_dijkstra_state *self,
								uint8_t length,
								t_ps_dijkstra_state *out);
void						ps_dijkstra_state_do_ss(
								t_ps_dijkstra_state *self,
								uint8_t length,
								t_ps_dijkstra_state *out);
void						ps_dijkstra_state_do_ra(
								t_ps_dijkstra_state *self,
								uint8_t length,
								t_ps_dijkstra_state *out);
void						ps_dijkstra_state_do_rb(
								t_ps_dijkstra_state *self,
								uint8_t length,
								t_ps_dijkstra_state *out);
void						ps_dijkstra_state_do_rr(
								t_ps_dijkstra_state *self,
								uint8_t length,
								t_ps_dijkstra_state *out);
void						ps_dijkstra_state_do_rra(
								t_ps_dijkstra_state *self,
								uint8_t length,
								t_ps_dijkstra_state *out);
void						ps_dijkstra_state_do_rrb(
								t_ps_dijkstra_state *self,
								uint8_t length,
								t_ps_dijkstra_state *out);
void						ps_dijkstra_state_do_rrr(
								t_ps_dijkstra_state *self,
								uint8_t length,
								t_ps_dijkstra_state *out);

# define PUSH_SWAP_OPERATION_NOP 0
# define PUSH_SWAP_OPERATION_PA 1
# define PUSH_SWAP_OPERATION_PB 2
# define PUSH_SWAP_OPERATION_SA 3
# define PUSH_SWAP_OPERATION_SB 4
# define PUSH_SWAP_OPERATION_SS 5
# define PUSH_SWAP_OPERATION_RA 6
# define PUSH_SWAP_OPERATION_RB 7
# define PUSH_SWAP_OPERATION_RR 8
# define PUSH_SWAP_OPERATION_RRA 9
# define PUSH_SWAP_OPERATION_RRB 10
# define PUSH_SWAP_OPERATION_RRR 11

typedef struct s_ps_dijkstra_operations
{
	uint8_t	length;
	uint8_t	operation[];
}	t_ps_dijkstra_operations;

t_ps_dijkstra_operations	*ps_dijkstra_operations_new(void);
t_ps_dijkstra_operations	*ps_dijkstra_operations_append(
								t_ps_dijkstra_operations *self,
								uint8_t value);
t_ps_dijkstra_operations	*ps_dijkstra_operations_reverse_order(
								t_ps_dijkstra_operations *self);
t_ps_dijkstra_operations	*ps_dijkstra_operations_reverse_rtl(
								t_ps_dijkstra_operations *self);
t_ps_dijkstra_operations	*ps_dijkstra_operations_reverse_order_rtl(
								t_ps_dijkstra_operations *self);

t_ft_simple_map_static		*ps_dijkstra_solution(
								uint8_t length);
t_ft_simple_map_static		*ps_dijkstra_solution_top(
								uint8_t length);
t_ft_simple_map_static		*ps_dijkstra_solution_bottom(
								uint8_t length);

#endif
