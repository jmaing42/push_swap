/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_append.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 01:34:05 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/20 01:40:01 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dijkstra.h"

#include "ft_malloc.h"
#include "ft_memory.h"

t_push_swap_dijkstra_operations	*push_swap_operations_append(
	t_push_swap_dijkstra_operations *self,
	uint8_t value
)
{
	t_push_swap_dijkstra_operations *const	result
		= (t_push_swap_dijkstra_operations *)ft_malloc(
			sizeof(t_push_swap_dijkstra_operations)
			+ sizeof(uint8_t) * (self->length + 1));

	result->length = self->length + 1;
	ft_memcpy(
		result->operation,
		self->operation,
		sizeof(uint8_t) * self->length);
	result->operation[self->length] = value;
	return (result);
}
