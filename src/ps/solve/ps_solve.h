/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:31:49 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/16 00:03:22 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SOLVE_H
# define PS_SOLVE_H

# include "ft_types.h"
# include "ps_stream.h"

typedef struct s_ps_solve_context
{
	t_ps_stream					*stream;
	struct s_ps_strategy_count	*table;
	size_t						table_size;
}	t_ps_solve_context;

typedef t_err	(*t_ps_solve)(
					t_ps_solve_context *context,
					int *arr,
					size_t length,
					bool from_right);

typedef struct s_ps_solve_count_item
{
	size_t	x;
	size_t	y;
	size_t	z;
	size_t	count;
}	t_ps_solve_count_item;

typedef struct s_ps_solve_count_part
{
	t_ps_solve_count_item	s;
	t_ps_solve				solve;
}	t_ps_solve_count_part;

typedef struct s_ps_solve_table
{
	t_ps_solve_count_part	tst;
	t_ps_solve_count_part	tsb;
	t_ps_solve_count_part	txt;
	t_ps_solve_count_part	txb;
	t_ps_solve_count_part	tot;
	t_ps_solve_count_part	tos;
	t_ps_solve_count_part	tob;
	t_ps_solve_count_part	sss;
	t_ps_solve_count_part	sxs;
	t_ps_solve_count_part	sot;
	t_ps_solve_count_part	sos;
	t_ps_solve_count_part	sob;
	t_ps_solve_count_part	bst;
	t_ps_solve_count_part	bsb;
	t_ps_solve_count_part	bxt;
	t_ps_solve_count_part	bxb;
	t_ps_solve_count_part	bot;
	t_ps_solve_count_part	bos;
	t_ps_solve_count_part	bob;
}	t_ps_solve_table;

#endif
