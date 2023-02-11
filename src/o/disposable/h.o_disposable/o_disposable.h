/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_file_name (file name is useless too)          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42header-remover <whatever@example.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by file history     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef O_DISPOSABLE_H
# define O_DISPOSABLE_H

# include "ft_types.h"

typedef struct s_o_disposable
{
	const struct s_o_disposable_vtable	*v;
}	t_o_disposable;

typedef void	(*t_o_disposable_dispose)(void *disposable);

typedef struct s_o_disposable_vtable
{
	const t_o_disposable_dispose	dispose;
}	t_o_disposable_vtable;

void	o_disposable_dispose(t_o_disposable *disposable);

#endif
