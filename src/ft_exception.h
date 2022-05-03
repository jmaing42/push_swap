/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:47:09 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/03 17:08:40 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXCEPTION_H
# define FT_EXCEPTION_H

# include <stddef.h>

# include "ft_types.h"

typedef struct s_exception_stacktrace_node
{
	struct s_exception_stacktrace_node	*next;
	const char							*file;
	int									line;
	char								*message;
}	t_exception_stacktrace_node;

typedef struct s_exception
{
	const struct s_exception_vtable	*v;
	const char						*message;
	const char						*file;
	int								line;
	t_exception_stacktrace_node		*stacktrace;
	size_t							stacktrace_skipped_count;
}	t_exception;

typedef void	(*t_exception_v_free)(
					t_exception *self);
typedef t_err	(*t_exception_v_print)(
					t_exception *self,
					int fd);
typedef char	*(*t_exception_v_getfile)(
					t_exception *self);
typedef int		(*t_exception_v_getline)(
					t_exception *self);
typedef t_err	(*t_exception_v_add_stacktrace)(
					t_exception *self,
					const char *file,
					int line,
					const char *message);

typedef const struct s_exception_vtable
{
	t_exception_v_free				free;
	t_exception_v_print				print;
	t_exception_v_getfile			getfile;
	t_exception_v_getline			getline;
	t_exception_v_add_stacktrace	add_stacktrace;
}	t_exception_vtable;

t_exception	*new_exception(
				const char *message,
				const char *file,
				int line);

#endif
