/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:17:26 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/06/14 00:07:29 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "ft_types.h"
# include "checker_state.h"

int				checker_exit(const char *message);

t_checker_state	*checker_init(size_t count, char **arr_as_string);

t_err			checker_do(t_checker_state *self, const char *operation);
bool			checker_sorted(t_checker_state *self);
void			checker_finalize(t_checker_state *self);

#endif
