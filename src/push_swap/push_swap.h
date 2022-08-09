/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 02:57:07 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/09 09:58:07 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_types.h"
# include "ps_solve.h"

t_err					push_swap_solve(const int *array, size_t length);

const t_ps_solve_table	*push_swap_get_table(void);
size_t					push_swap_get_table_size(void);

#endif
