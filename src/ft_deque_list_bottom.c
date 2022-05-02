/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_list_bottom.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:41:56 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/02 21:19:34 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_list_internal.h"

#include <stdlib.h>

static const t_deque_iterator_vtable	g_v = {
	(t_deque_iterator_v_delete)(&ft_deque_list_iterator_v_delete),
	(t_deque_iterator_v_has_next)(&ft_deque_list_iterator_v_has_next_bottomup),
	(t_deque_iterator_v_get_next)(&ft_deque_list_iterator_v_get_next_bottomup)
};

t_err	ft_deque_list_v_push_bottom(
	t_deque_list *self,
	void *value,
	t_exception **exception
)
{
	t_deque_list_node *const	new_node = (t_deque_list_node *)malloc(
			sizeof(t_deque_list_node));

	if (!new_node)
	{
		*exception = new_exception("malloc() failed", __FILE__, __LINE__);
		return (true);
	}
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = self->tail;
	if (self->tail)
		self->tail->next = new_node;
	self->tail = new_node;
	return (false);
}

bool	ft_deque_list_v_pop_bottom(
	t_deque_list *self,
	void **out
)
{
	t_deque_list_node *const	current = self->tail;

	if (!current)
		return (false);
	*out = current->value;
	self->tail = current->prev;
	if (!self->tail)
		self->head = NULL;
	if (current->prev)
		current->prev->next = NULL;
	free(current);
	return (true);
}

t_err	ft_deque_list_v_peek_bottom(
	t_deque_list *self,
	void **out,
	t_exception **exception
)
{
	if (!self->tail)
	{
		if (exception)
			*exception = new_exception(
					"peek_bottom() called but no element", __FILE__, __LINE__);
		return (true);
	}
	*out = self->tail->value;
	return (false);
}

t_err	ft_deque_list_v_rotate_bottom(
	t_deque_list *self,
	t_exception **exception
)
{
	t_deque_list_node *const	current = self->tail;

	(void) exception;
	if (current == self->head)
		return (false);
	self->tail = current->prev;
	current->prev->next = NULL;
	current->prev = NULL;
	current->next = self->head;
	self->head->prev = current;
	self->head = current;
	return (false);
}

t_err	ft_deque_list_v_iterator_bottomup(
	t_deque_list *self,
	t_deque_list_iterator **out,
	t_exception **exception
)
{
	t_deque_list_iterator *const	result = (t_deque_list_iterator *) malloc(
			sizeof(t_deque_list_iterator));

	if (!result)
	{
		if (exception)
			*exception = new_exception("malloc() failed", __FILE__, __LINE__);
		return (true);
	}
	result->v = (t_deque_iterator_vtable *)&g_v;
	result->node = self->head;
	*out = result;
	return (false);
}
