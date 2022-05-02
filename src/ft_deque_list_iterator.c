/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_list_iterator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:27:56 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/02 21:18:46 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_list_internal.h"

#include <stdlib.h>

void	ft_deque_list_iterator_v_delete(t_deque_list_iterator *self)
{
	free(self);
}

bool	ft_deque_list_iterator_v_has_next_topdown(t_deque_list_iterator *self)
{
	return (!!self->node->next);
}

bool	ft_deque_list_iterator_v_get_next_topdown(
	t_deque_list_iterator *self,
	void **out
)
{
	if (!self->node)
		return (false);
	self->node = self->node->next;
	*out = self->node->value;
	return (true);
}

bool	ft_deque_list_iterator_v_has_next_bottomup(t_deque_list_iterator *self)
{
	return (!!self->node->prev);
}

bool	ft_deque_list_iterator_v_get_next_bottomup(
	t_deque_list_iterator *self,
	void **out
)
{
	if (!self->node)
		return (false);
	self->node = self->node->prev;
	*out = self->node->value;
	return (true);
}
