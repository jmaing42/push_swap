/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_dijkstra.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:25:28 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/18 00:58:32 by Juyeong Maing    ###   ########.fr       */
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

t_ps_dijkstra_state			*ps_dijkstra_state_new_superposition(
								uint8_t length,
								bool has_divider);
t_ps_dijkstra_state			*ps_dijkstra_state_new_top(
								uint8_t length,
								bool has_divider);
t_ps_dijkstra_state			*ps_dijkstra_state_new_bottom(
								uint8_t length,
								bool has_divider);

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

# define PS_DIJKSTRA_OPERATION_PA 1
# define PS_DIJKSTRA_OPERATION_PB 2
# define PS_DIJKSTRA_OPERATION_SA 3
# define PS_DIJKSTRA_OPERATION_SB 4
# define PS_DIJKSTRA_OPERATION_SS 5
# define PS_DIJKSTRA_OPERATION_RA 6
# define PS_DIJKSTRA_OPERATION_RB 7
# define PS_DIJKSTRA_OPERATION_RR 8
# define PS_DIJKSTRA_OPERATION_RRA 9
# define PS_DIJKSTRA_OPERATION_RRB 10
# define PS_DIJKSTRA_OPERATION_RRR 11

uint8_t						ps_dijkstra_operation_reverse_order(
								uint8_t operation);

typedef struct s_ps_dijkstra_operations
{
	uint8_t	length;
	uint8_t	operation[];
}	t_ps_dijkstra_operations;

t_ps_dijkstra_operations	*ps_dijkstra_operations_new(void);
t_ps_dijkstra_operations	*ps_dijkstra_operations_append(
								t_ps_dijkstra_operations *self,
								uint8_t value);
t_ps_dijkstra_operations	*ps_dijkstra_operations_copy(
								t_ps_dijkstra_operations *self);
t_ps_dijkstra_operations	*ps_dijkstra_operations_reverse_order(
								t_ps_dijkstra_operations *self);

t_ft_simple_map_static		*ps_dijkstra_get_all_cases(
								t_ps_dijkstra_state initial_state);
const char *const			*ps_dijkstra_solution_tst(
								uint8_t length);
const char *const			*ps_dijkstra_solution_txt(
								uint8_t length);
const char *const			*ps_dijkstra_solution_tsb(
								uint8_t length);
const char *const			*ps_dijkstra_solution_txb(
								uint8_t length);
const char *const			*ps_dijkstra_solution_tot(
								uint8_t length);
const char *const			*ps_dijkstra_solution_tos(
								uint8_t length);
const char *const			*ps_dijkstra_solution_tob(
								uint8_t length);
const char *const			*ps_dijkstra_solution_ssb(
								uint8_t length);
const char *const			*ps_dijkstra_solution_sxb(
								uint8_t length);
const char *const			*ps_dijkstra_solution_sot(
								uint8_t length);
const char *const			*ps_dijkstra_solution_sob(
								uint8_t length);
const char *const			*ps_dijkstra_solution_bst(
								uint8_t length);
const char *const			*ps_dijkstra_solution_bxt(
								uint8_t length);
const char *const			*ps_dijkstra_solution_bsb(
								uint8_t length);
const char *const			*ps_dijkstra_solution_bxb(
								uint8_t length);
const char *const			*ps_dijkstra_solution_bot(
								uint8_t length);
const char *const			*ps_dijkstra_solution_bos(
								uint8_t length);
const char *const			*ps_dijkstra_solution_bob(
								uint8_t length);

const char					*ps_dijkstra_find(
								const char *const *solution,
								size_t length,
								int *array);

#endif
