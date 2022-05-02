/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_list_internal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:06:30 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/02 20:47:06 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_list_internal.h"

#include <stdlib.h>

static const t_deque_vtable	g_v = {
	(t_deque_v_delete)(&ft_deque_list_v_delete),
	(t_deque_v_get_length)(&ft_deque_list_v_get_length),
	(t_deque_v_push)(&ft_deque_list_v_push_top),
	(t_deque_v_push)(&ft_deque_list_v_push_bottom),
	(t_deque_v_pop)(&ft_deque_list_v_pop_top),
	(t_deque_v_pop)(&ft_deque_list_v_pop_bottom),
	(t_deque_v_peek)(&ft_deque_list_v_peek_top),
	(t_deque_v_peek)(&ft_deque_list_v_peek_bottom),
	(t_deque_v_rotate)(&ft_deque_list_v_rotate_top),
	(t_deque_v_rotate)(&ft_deque_list_v_rotate_bottom),
	(t_deque_v_iterator)(&ft_deque_list_v_iterator_topdown),
	(t_deque_v_iterator)(&ft_deque_list_v_iterator_bottomup)
};

t_deque	*new_deque_list(void (*cleaner)(void *))
{
	t_deque_list *const	result = (t_deque_list *)malloc(sizeof(t_deque_list));

	if (!result)
		return (NULL);
	result->v = &g_v;
	result->head = NULL;
	result->tail = NULL;
	result->length = 0;
	result->cleaner = cleaner;
	return ((t_deque *)result);
}

void	ft_deque_list_v_delete(t_deque_list *self)
{
	t_deque_list_node	*next;
	t_deque_list_node	*current;

	next = self->head;
	while (next)
	{
		current = next;
		next = current->next;
		self->cleaner(current->value);
		free(current);
	}
	free(self);
}

size_t	ft_deque_list_v_get_length(t_deque_list *self)
{
	return (self->length);
}
