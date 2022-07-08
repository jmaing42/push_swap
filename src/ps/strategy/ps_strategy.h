/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:45:05 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/08 09:28:52 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRATEGY_H
# define PS_STRATEGY_H

# include <stddef.h>

# include "ps_stream.h"

typedef struct s_ps_strategy_count_item
{
	size_t	x;
	size_t	y;
	size_t	z;
	size_t	moves;
}	t_ps_strategy_count_item;

typedef t_err	(*t_ps_solve)(struct s_ps_solve_param context);

typedef struct s_ps_strategy_count_part
{
	t_ps_strategy_count_item	item;
	t_ps_solve					func;
	const char					*name;
}	t_ps_strategy_count_part;

typedef struct s_ps_strategy_count
{
	t_ps_strategy_count_part	tst;
	t_ps_strategy_count_part	txt;
	t_ps_strategy_count_part	tsb;
	t_ps_strategy_count_part	txb;
	t_ps_strategy_count_part	tot;
	t_ps_strategy_count_part	tos;
	t_ps_strategy_count_part	tob;
	t_ps_strategy_count_part	bst;
	t_ps_strategy_count_part	bxt;
	t_ps_strategy_count_part	bsb;
	t_ps_strategy_count_part	bxb;
	t_ps_strategy_count_part	bot;
	t_ps_strategy_count_part	bos;
	t_ps_strategy_count_part	bob;
	t_ps_strategy_count_part	sss;
	t_ps_strategy_count_part	sxs;
	t_ps_strategy_count_part	sot;
	t_ps_strategy_count_part	sob;
	t_ps_strategy_count_part	sos;
}	t_ps_strategy_count;

void	ps_strategy_init(
			t_ps_strategy_count *table,
			size_t count_from,
			size_t count_to_exclusive);

typedef struct s_ps_solve_param
{
	t_ps_strategy_count	*map;
	t_ps_stream			*output;
	size_t				count;
	int					*arr;
	bool				from_right;
}	t_ps_solve_param;

#endif
