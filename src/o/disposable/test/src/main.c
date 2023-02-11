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

#include "o_disposable.h"

#include <stdbool.h>
#include <assert.h>

static bool							g_is_disposed = false;

static void	assert_disposed(bool is_disposed)
{
	assert(is_disposed == g_is_disposed);
}

static void	dispose(void *unused)
{
	(void)unused;
	g_is_disposed = true;
}

typedef struct s_my_disposable
{
	const t_o_disposable_vtable	*v;
}	t_my_disposable;

static const t_o_disposable_vtable	g_vtable = {dispose};

int	main(void)
{
	const t_my_disposable	disposable_src = {&g_vtable};
	t_o_disposable *const	disposable_ref = (t_o_disposable *)&disposable_src;

	assert_disposed(false);
	o_disposable_dispose(disposable_ref);
	assert_disposed(true);
}
