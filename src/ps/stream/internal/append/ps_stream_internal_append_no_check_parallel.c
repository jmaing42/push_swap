/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stream_internal_append_no_check_parallel.c      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:52:25 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/14 23:54:12 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stream_internal.h"

void	ps_stream_internal_append_no_check_parallel(
	t_ps_stream_node_parallel_list *list,
	size_t count
)
{
	list->tail->count += count;
}
