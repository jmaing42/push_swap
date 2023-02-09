/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_args.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 2023/02/09 22:36:35 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_PARSE_ARGS_H
# define PS_PARSE_ARGS_H

# include <stdlib.h>

# include "ft_types.h"

t_err	ps_parse_args(size_t argc, const char *const *argv);
t_err	ps_parse_args_atoi(const char *str, int *out);

#endif
