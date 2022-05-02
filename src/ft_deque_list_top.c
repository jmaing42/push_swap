/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_list_top.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:41:56 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/02 21:19:29 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_list_internal.h"

#include <stdlib.h>

static const t_deque_iterator_vtable	g_v = {
	(t_deque_iterator_v_delete)(&ft_deque_list_iterator_v_delete),
	(t_deque_iterator_v_has_next)(&ft_deque_list_iterator_v_has_next_topdown),
	(t_deque_iterator_v_get_next)(&ft_deque_list_iterator_v_get_next_topdown)
};

t_err	ft_deque_list_v_push_top(
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
	new_node->prev = NULL;
	new_node->next = self->head;
	if (self->head)
		self->head->prev = new_node;
	self->head = new_node;
	return (false);
}

bool	ft_deque_list_v_pop_top(
	t_deque_list *self,
	void **out
)
{
	t_deque_list_node *const	current = self->head;

	if (!current)
		return (false);
	*out = current->value;
	self->head = current->next;
	if (!self->head)
		self->tail = NULL;
	if (current->next)
		current->next->prev = NULL;
	free(current);
	return (true);
}

t_err	ft_deque_list_v_peek_top(
	t_deque_list *self,
	void **out,
	t_exception **exception
)
{
	if (!self->head)
	{
		if (exception)
			*exception = new_exception(
					"peek_top() called but no element", __FILE__, __LINE__);
		return (true);
	}
	*out = self->head->value;
	return (false);
}

t_err	ft_deque_list_v_rotate_top(
	t_deque_list *self,
	t_exception **exception
)
{
	t_deque_list_node *const	current = self->head;

	(void) exception;
	if (current == self->tail)
		return (false);
	self->head = current->next;
	current->next->prev = NULL;
	current->next = NULL;
	current->prev = self->tail;
	self->tail->next = current;
	self->tail = current;
	return (false);
}

t_err	ft_deque_list_v_iterator_topdown(
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
