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

#ifndef PS_PARSE_ARGS_H
# define PS_PARSE_ARGS_H

# include <stdlib.h>

# include "ft_types.h"

t_err	ps_parse_args(size_t argc, const char *const *argv);
t_err	ps_parse_args_atoi(const char *str, int *out);

#endif
