/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_new.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 01:34:05 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/05/20 02:41:26 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dijkstra.h"

#include "ft_malloc.h"

t_push_swap_dijkstra_operations	*push_swap_operations_new(void)
{
	t_push_swap_dijkstra_operations *const	result
		= (t_push_swap_dijkstra_operations *)ft_malloc(
			sizeof(t_push_swap_dijkstra_operations));

	result->length = 0;
	return (result);
}
