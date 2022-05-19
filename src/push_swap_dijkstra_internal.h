/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dijkstra_internal.h                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 02:31:31 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/20 02:50:05 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_DIJKSTRA_INTERNAL_H
# define PUSH_SWAP_DIJKSTRA_INTERNAL_H

# include "push_swap_dijkstra.h"

void					push_swap_dijkstra_common(
							t_ft_simple_map_static *map,
							t_push_swap_dijkstra_state *initial_state,
							uint8_t length
							);

t_ft_simple_map_static	*push_swap_dijkstra_finalize(
							t_ft_simple_map_static *map,
							uint8_t length
							);

t_ft_simple_map_static	*push_swap_dijkstra_finalize_top(
							t_ft_simple_map_static *map,
							uint8_t length
							);

t_ft_simple_map_static	*push_swap_dijkstra_finalize_bottom(
							t_ft_simple_map_static *map,
							uint8_t length
							);

#endif
