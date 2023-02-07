/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:17:26 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/30 00:14:37 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "ft_types.h"
# include "ps_stack.h"

int				checker_exit(const char *message);

t_ps_stack		*checker_init(size_t count, char **arr_as_string);

t_err			checker_do(t_ps_stack *self, const char *operation);
bool			checker_sorted(t_ps_stack *self);
void			checker_finalize(t_ps_stack *self);

#endif
