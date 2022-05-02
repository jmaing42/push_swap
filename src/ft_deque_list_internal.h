/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_list_internal.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:06:30 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/02 21:02:31 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_LIST_INTERNAL_H
# define FT_DEQUE_LIST_INTERNAL_H

# include "ft_deque_list.h"

typedef struct s_deque_list_node
{
	struct s_deque_list_node	*next;
	struct s_deque_list_node	*prev;
	void						*value;
}	t_deque_list_node;

typedef struct s_deque_list
{
	const t_deque_vtable	*v;
	size_t					length;
	t_deque_list_node		*head;
	t_deque_list_node		*tail;
	void					(*cleaner)(void *);
}	t_deque_list;

typedef struct s_deque_list_iterator
{
	struct s_deque_iterator_vtable	*v;
	t_deque_list_node				*node;
}	t_deque_list_iterator;

void	ft_deque_list_v_delete(t_deque_list *self);
size_t	ft_deque_list_v_get_length(
			t_deque_list *self);
t_err	ft_deque_list_v_push_top(
			t_deque_list *self,
			void *value,
			t_exception **exception);
t_err	ft_deque_list_v_push_bottom(
			t_deque_list *self,
			void *value,
			t_exception **exception);
bool	ft_deque_list_v_pop_top(
			t_deque_list *self,
			void **out);
bool	ft_deque_list_v_pop_bottom(
			t_deque_list *self,
			void **out);
t_err	ft_deque_list_v_peek_top(
			t_deque_list *self,
			void **out,
			t_exception **exception);
t_err	ft_deque_list_v_peek_bottom(
			t_deque_list *self,
			void **out,
			t_exception **exception);
t_err	ft_deque_list_v_rotate_top(
			t_deque_list *self,
			t_exception **exception);
t_err	ft_deque_list_v_rotate_bottom(
			t_deque_list *self,
			t_exception **exception);
t_err	ft_deque_list_v_iterator_topdown(
			t_deque_list *self,
			t_deque_list_iterator **out,
			t_exception **exception);
t_err	ft_deque_list_v_iterator_bottomup(
			t_deque_list *self,
			t_deque_list_iterator **out,
			t_exception **exception);
void	ft_deque_list_iterator_v_delete(t_deque_list_iterator *self);
bool	ft_deque_list_iterator_v_has_next_topdown(t_deque_list_iterator *self);
bool	ft_deque_list_iterator_v_get_next_topdown(
			t_deque_list_iterator *self,
			void **out);
bool	ft_deque_list_iterator_v_has_next_bottomup(t_deque_list_iterator *self);
bool	ft_deque_list_iterator_v_get_next_bottomup(
			t_deque_list_iterator *self,
			void **out);

#endif
