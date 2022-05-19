/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_new.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 01:34:05 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/20 01:38:58 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dijkstra.h"

#include "ft_malloc.h"

t_push_swap_dijkstra_operations	*push_swap_operations_new(
	uint8_t value
)
{
	t_push_swap_dijkstra_operations *const	result
		= (t_push_swap_dijkstra_operations *)ft_malloc(
			sizeof(t_push_swap_dijkstra_operations) + sizeof(uint8_t));

	result->length = 1;
	result->operation[0] = value;
	return (result);
}
