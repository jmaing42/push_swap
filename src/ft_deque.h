/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:28:07 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/02 21:01:59 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_H
# define FT_DEQUE_H

# include <stddef.h>

# include "ft_types.h"
# include "ft_exception.h"

typedef struct s_deque
{
	const struct s_deque_vtable	*v;
}	t_deque;

typedef struct s_deque_iterator
{
	const struct s_deque_iterator_vtable	*v;
}	t_deque_iterator;

typedef void	(*t_deque_iterator_v_delete)(t_deque_iterator *self);
typedef bool	(*t_deque_iterator_v_has_next)(t_deque_iterator *self);
typedef bool	(*t_deque_iterator_v_get_next)(
					t_deque_iterator *self,
					void **out);

typedef struct s_deque_iterator_vtable
{
	t_deque_iterator_v_delete	free;
	t_deque_iterator_v_has_next	has_next;
	t_deque_iterator_v_get_next	get_next;
}	t_deque_iterator_vtable;

typedef void	(*t_deque_v_delete)(t_deque *self);
typedef size_t	(*t_deque_v_get_length)(
					t_deque *self);
typedef t_err	(*t_deque_v_push)(
					t_deque *self,
					void *value,
					t_exception **exception);
typedef bool	(*t_deque_v_pop)(
					t_deque *self,
					void **out);
typedef t_err	(*t_deque_v_peek)(
					t_deque *self,
					void **out,
					t_exception **exception);
typedef t_err	(*t_deque_v_rotate)(
					t_deque *self,
					t_exception **exception);
typedef t_err	(*t_deque_v_iterator)(
					t_deque *self,
					t_deque_iterator **out,
					t_exception **exception);

typedef struct s_deque_vtable
{
	t_deque_v_delete		free;
	t_deque_v_get_length	get_length;
	t_deque_v_push			push_top;
	t_deque_v_push			push_bottom;
	t_deque_v_pop			pop_top;
	t_deque_v_pop			pop_bottom;
	t_deque_v_peek			peek_top;
	t_deque_v_peek			peek_bottom;
	t_deque_v_rotate		rotate_top;
	t_deque_v_rotate		rotate_bottom;
	t_deque_v_iterator		iterator_topdown;
	t_deque_v_iterator		iterator_bottomup;
}	t_deque_vtable;

#endif
